#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int a[N], b[N];
bool u[N];
int n, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        FOR(i, 0, n) {
            cin >> a[i];
        }
        FOR(i, 0, n) {
            cin >> b[i];
        }

        memset(u, 0, sizeof(u));

        while (true) {
            bool c = true;
            FOR(i, 0, n) {
                if (a[i] <= k && u[i] == false) {
                    k += b[i];
                    u[i] = true;
                    c = false;
                }
            }
            if (c) break;
        }

        cout << k << '\n';
    }
    return 0;
}