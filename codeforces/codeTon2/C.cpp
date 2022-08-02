#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, ans, a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        rep(i, 0, m) cin >> a[i];
        sort(a, a + m);

        vector<ll> vec;
        ll rem = 0;
        rep(i, 0, m) {
            if (i == 0) {
                rem += a[i] - 1;
            }
            
            if (i == m - 1) {
                rem += n - a[i];
            }
            
            if (i > 0) {
                ll x = a[i] - a[i-1] - 1;
                if (x > 0)
                    vec.push_back(x);
            }
        }
        if (rem > 0)
            vec.push_back(rem);
        sort(vec.rbegin(), vec.rend());

        ll t = 0;
        ll saved = 0;
        rep(i, 0, vec.size()) {
            auto len = vec[i];
            auto x = vec[i] - (2 * t);
            if (x <= 0) continue;
            if (x <= 2) {
                t++;
                saved += 1;
            } else if (x >= 3) {
                t += 2;
                saved += x - 1;
            }
        }

        ll ans = n - saved;
        cout << ans << '\n';
    }

    return 0;
}