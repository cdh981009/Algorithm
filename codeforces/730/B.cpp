#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 201010;

int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n; cin >> n;
        ll sum = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            sum += x;
            arr[i] = x;
        }
        ll avg = sum / n;
        ll rem = sum - avg * n;
        ll ans = (n - rem) * rem;
        cout << ans << '\n';
    }
    return 0;
}