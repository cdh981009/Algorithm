#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5 + 10;

int ans;
int arr[N];
int n;

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
        ll x, y;
        cin >> n >> x >> y;
        ll sum = 0;
        FOR(i, 0, n) {
            cin >> arr[i];
            sum += arr[i];
        }

        bool p = false;
        if (y % 2) {
            if ((sum % 2) ^ (x % 2)) p = true;
            
        } else {
            if ((sum % 2) == (x % 2)) p = true;
        }

        cout << (p ? "Alice" : "Bob") << '\n';
    }
    return 0;
}