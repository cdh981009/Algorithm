#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;

int n, k;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1 && k >= 0; ++i) {
            int x = min(arr[i], k);
            k -= x;
            arr[i] -= x;
            arr[n - 1] += x;
        }
        FOR(i, 0, n) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}