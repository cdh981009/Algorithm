#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int(i) = (a); (i) <= (b); ++(i))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 5;
constexpr int M = 201010;

int n;
bool adj[N][N];
bool aux[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    if (n != 10) {
        int ans = 0;
        int cnt = 0;
        int cross[6];
        FOR(i, 0, 5) {
            cross[i] = 0;
        }
        FOR(i, 0, 5) {
            FOR(j, i + 1, 5) {
                int k = (i + 2) % 5;
                int l = (j + 2) % 5;
                if (i == l || j == k)
                    continue;
                if (adj[i][k] && adj[j][l]) {
                    cross[i]++;
                    cross[k]++;
                    cross[j]++;
                    cross[l]++;
                    cnt++;
                }
            }
        }

        if (cnt == 0) {
            ans = 0;

        } else {
            FOR_(i, 1, 5) {
                if (cross[i] == cnt) {
                    cnt = -1;
                    ans = 1;
                    break;
                }
            }
            if (cnt != -1) {
                ans = 2;
            }
        }
        
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}