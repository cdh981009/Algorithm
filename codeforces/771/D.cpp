#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1010;
constexpr int M = 100;

int n, m;
int a[N][N];
bool painted[N][N];
vector<pair<pii, int>> v;

bool inBound(int x, int y) {
    return (x >= 0 && x < n - 1 && y >= 0 && y < m - 1);
}

// return primal color, -1 if mixed
int paintable(int x, int y) {
    int c = 0;

    FOR_(i, 0, 1) {
        FOR_(j, 0, 1) {
            if (a[x + i][y + j] != 0) {
                if (c == 0) {
                    c = a[x + i][y + j];
                } else if (a[x + i][y + j] != c) {
                    return -1;
                }
            }
        }
    }

    return c;
}

void dfs(int x, int y) {
    if (!inBound(x, y)) return;
    if (painted[x][y]) return;

    int p = paintable(x, y);
    if (p == -1) return;
    // cout << x << ' ' << y << '\n';
    painted[x][y] = true;
    if (p == 0) return;

    v.push_back({{x + 1, y + 1}, p});

    FOR_(i, 0, 1)
        FOR_(j, 0, 1)
            a[x + i][y + j] = 0;
    
    FOR_(i, -1, 1) {
        FOR_(j, -1, 1) {
            if (i == 0 && j == 0) continue;
            dfs(x + i, y + j);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    bool pos = true;

    FOR(i, 0, n)
        FOR(j, 0, m)
            cin >> a[i][j];

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (!painted[i][j])
                dfs(i, j);
        }
    }

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (a[i][j] != 0) {
                pos = false;
                break;
            }
        }
    }

    if (!pos) {
        cout << "-1\n";
    } else {
        cout << v.size() << '\n';
        FOR(i, 0, v.size()) {
            auto &[p, c] = v[v.size() - i - 1];
            cout << p.first << ' ' << p.second << ' ' << c << '\n';
        }
    }

    return 0;
}