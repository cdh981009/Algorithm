#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int M = 1e9 + 7;

int n, m;
vector<pii> edges[N];
vector<int> pEdges[N];
bool pos = true;
int col[N];
int ans[N];
int cnt = 0;

void dfs1(int node, int color) {
    col[node] = color;
    
    int ncolor = !color;

    for (auto &[c, t] : edges[node]) {
        if (col[c] != -1) {
            if (col[c] == color) {
                pos = false;
                return;
            }
        } else {
            dfs1(c, ncolor);
        }

        if (color == 0 && t == 2) {
            pEdges[node].push_back(c);
        } else if (color == 1 && t == 1) {
            pEdges[node].push_back(c);
        }
    }
}

void dfs2(int node) {
    ans[node] = -2;

    for (auto &c : pEdges[node]) {
        if (ans[c] == -2) {
            pos = false;
            break;
        } else if (ans[c] == -1) {
            dfs2(c);
        }
    }

    ans[node] = cnt++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(col, -1, sizeof(col));
    memset(ans, -1, sizeof(ans));

    cin >> n >> m;
    
    FOR(i, 0, m) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) t = 2;
        else t = 1;
        a--;
        b--;
        edges[a].push_back({b, t});
        edges[b].push_back({a, t});
    }

    FOR(i, 0, n) {
        if (col[i] == -1) 
            dfs1(i, 0);
    }

    if (pos) {
        FOR(i, 0, n) {
            if (ans[i] == -1) 
                dfs2(i);
        }
    }

    if (!pos) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        FOR(i, 0, n) {
            cout << (col[i] == 0 ? "R " : "L ") << ans[i] << '\n';
        }
    }

    return 0;
}