#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2000;

int arr[N];
int n;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        sort(arr, arr + n, [](int a, int b) {
            return a % 2 < b % 2;
        });

        FOR(i, 0, n) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}