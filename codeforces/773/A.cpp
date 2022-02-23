#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
constexpr int M = 100;

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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        map<ll, int> m;
        FOR(i, 0, n) {
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a.begin(), a.end());
        
        int ans = 0;
        FOR(i, 0, n) {
            ll c = a[i];
            if (m[c] == 0) continue;
            if (m.count(c * x) > 0) {
                m[c * x]--;
            } else {
                ans++;
            }
            m[c]--;
        }

        cout << ans << '\n';
    }

    return 0;
}