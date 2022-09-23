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

constexpr int N = 350000;
constexpr int M = 100;

vector<int> edges[N];
vector<vector<int>> ans;
bool grouped[N];
int parent[N];
int childCnt[N];  // num of child
int with[N];

void dfs(int node, int p) {
    node[parent] = p;

    for (auto &child : edges[node]) {
        if (child == p) continue;
        childCnt[node]++;
        dfs(child, node);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    bool pos = true;

    dfs(1, 0);

    queue<int> q;
    rep_(i, 1, n) {
        if (childCnt[i] == 0) q.push(i);
    }
    grouped[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int p = parent[node];
        childCnt[p]--;

        if (!grouped[node]) {
            grouped[node] = true;

            if (grouped[p]) {
                pos = false;
                break;
            }

            // group with parent
            if (with[p] == 0) {
                if (with[node] != 0) {
                    grouped[p] = true;
                    ans.push_back({with[node], p, node});
                }
                with[p] = node;
            } else {
                grouped[p] = true;
                ans.push_back({with[p], p, node});
            }
        }

        if (childCnt[p] == 0) {
            q.push(p);
        }
    }

    if (pos) {
        cout << "S\n";
        for (auto &v : ans) {
            for (auto &x : v) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "U\n";
    }

    return 0;
}