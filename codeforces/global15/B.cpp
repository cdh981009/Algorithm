#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 50010;
int arr[N][5];
int perm[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        int ans = 0;

        FOR(i, 0, n) {
            FOR(j, 0, 5) {
                int x;
                cin >> x;
                arr[i][j] = x;
            }
            perm[i] = i;
        }

        if (n >= 2) {
            auto comp = [](int x, int y) -> bool {
                int g = 0;
                FOR(i, 0, 5) {
                    if (arr[x][i] < arr[y][i])
                        g++;
                }
                return g >= 3;
            };

            FOR(i, 1, n) {
                if (comp(perm[i - 1], perm[i]))
                    swap(perm[i - 1], perm[i]);
            }
            bool valid = true;
            FOR(i, 0, n - 1) {
                if (comp(perm[i], perm[n - 1])) {
                    valid = false;
                    break;
                }
            }
            ans = valid ? perm[n - 1] + 1 : - 1;
        } else {
            ans = 1;
        }

        cout << ans << '\n';
    }
    return 0;
}