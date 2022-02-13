#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 5001;
constexpr int M = 998244353;

int n, k;
string str;
ll dp[N][N];
ll ans;

ll comb(int n, int r) {
    if (n == r || r == 0) return 1;
    if (r > n / 2) r = n - r;

    ll& ref = dp[n][r];
    if (ref != -1) return ref;
    return ref = (comb(n - 1, r) + comb(n - 1, r - 1)) % M;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    cin >> str;

    if (k != 0) {
        vector<pii> v;
        FOR(i, 0, n) {
            if (str[i] == '0') continue;
            int s, e;
            for (s = i; s - 1 >= 0; --s)
                if (str[s - 1] == '1') break;

            int cnt = 1;
            for (e = i; e + 1 < n; ++e) {
                if (str[e + 1] == '1') {
                    cnt++;
                    if (cnt > k) {
                        cnt--;
                        break;
                    }
                }
            }

            if (cnt == k) {
                v.push_back({s, e});
            }
        }

        ans = 1;
        FOR(i, 0, v.size()) {
            auto& p = v[i];
            if (i == 0)
                ans += comb(p.second - p.first + 1, k) - 1;
            else {
                int prev = v[i - 1].second;
                ans += comb(p.second - p.first + 1, k);
                ans -= comb(prev - p.first + 1, k - 1);
            }
            ans += M;
            ans %= M;
        }

    } else {
        ans = 1;
    }
    cout << ans << '\n';
    return 0;
}