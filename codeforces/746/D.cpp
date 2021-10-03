#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1010;

vector<int> edge[N];
vector<pii> edges;
bool chk[N];
bool ed[N];
int target;
int n;

void dfs(int node, int par) {
    FOR(i, 0, edge[node].size()) {
        int child = edge[node][i];
        if (child == par)
            continue;
        edges.push_back({node, child});
        dfs(child, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1, 0);

    int l = 0;
    int r = n - 2;
    FOR(q, 0, 12) {
        int m;
        memset(chk, false, sizeof(chk));
        if (r == l)
            break;
        if (q == 0)
            m = r;
        else
            m = (l + r) / 2;

        FOR_(i, l, m) {
            auto& p = edges[i];
            chk[p.first] = chk[p.second] = true;
        }
        vector<int> qs;
        FOR_(i, 1, n) {
            if (chk[i]) {
                qs.push_back(i);
            }
        }
        cout << "? " << qs.size() << ' ';
        for (auto v : qs) {
            cout << v << ' ';
        }
        cout << '\n';
        cout.flush();

        if (q == 0) {
            cin >> target;
        } else {
            int x;
            cin >> x;
            if (x == target) {
                //  [l.. m]
                l = l;
                r = m;
            } else {
                l = m + 1;
                r = r;
            }
        }
    }

    auto& p = edges[l];
    int a = p.first;
    int b = p.second;
    cout << "! " << a << ' ' << b << '\n';
    cout.flush();

    return 0;
}