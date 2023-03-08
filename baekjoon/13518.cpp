#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 1010101;

int n, q, weight[N], first[N], last[N]; 
int wcnt[M], ncnt[N], nmxcnt[N]; // weight count, node count
vector<int> edge[N];
vector<int> ett;

void dfs(int node, int prev) {
    first[node] = ett.size();
    ett.push_back(node);
    nmxcnt[node]++;

    for (auto child : edge[node]) {
        if (child == prev) continue;

        dfs(child, node);
        ett.push_back(node);
        nmxcnt[node]++;
    }

    last[node] = ett.size();
    ett.push_back(node);
    nmxcnt[node]++;
}

struct Query {
    int l, r, i;
    bool operator< (const Query& o) const {
        return this->l < o.l;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 0, n) {
        cin >> weight[i + 1];
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1, 0);

    int sq = sqrt(ett.size());

    vector<vector<Query>> qs(sq + 2);

    cin >> q;
    vector<int> ans(q);

    rep(i, 0, q) {
        int u, v; cin >> u >> v;
        int l, r;
        if (first[u] > first[v]) swap(u, v); // u enters first in ett!
        if (last[u] < first[v]) { // not overlapping: sibling
            l = last[u], r = first[v];
        } else { // overlapping: subtree
            l = first[u], r = first[v];
        }

        qs[r / sq].push_back({l, r, i});
    }

    int curl, curr;
    int count = 0;
    curl = curr = 0;

    auto add = [&](int ind) {
        int x = ett[ind];
        int w = weight[x];

        ncnt[x]++;

        if (ncnt[x] == nmxcnt[x]) { // become overlap -> remove
            wcnt[w]--;
            if (wcnt[w] == 0) count--;
        }

        if (ncnt[x] == 1) { // newly come in to range -> add
            wcnt[w]++;
            if (wcnt[w] == 1) count++;
        }
    };

    auto del = [&](int ind) {
        int x = ett[ind];
        int w = weight[x];

        ncnt[x]--;

        if (ncnt[x] == nmxcnt[x] - 1) { // become unoverlap -> add
            wcnt[w]++;
            if (wcnt[w] == 1) count++;
        }

        if (ncnt[x] == 0) { // get out of range -> remove
            wcnt[w]--;
            if (wcnt[w] == 0) count--;
        }
    };

    add(0);

    for (auto& v : qs) {
        sort(v.begin(), v.end());

        for (auto& [l, r, i] : v) {
            while (curr < r) add(++curr);
            while (curr > r) del(curr--);

            while (curl < l) del(curl++);
            while (curl > l) add(--curl);

            ans[i] = count;
        }
    }

    rep(i, 0, q) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}