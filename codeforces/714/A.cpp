#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 100;

int arr[N];
int n, k;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        if (k >= (n + 1) / 2) {
            cout << -1 << '\n';
        } else {
            int x = 0;
            FOR(i, 0, n - k) {
                cout << i + 1 << ' ';
                if (x < k) {
                    cout << n - x << ' ';
                    x++;
                }
            }
            cout << '\n';
        }
    }
    return 0;
}