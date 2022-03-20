#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 51010;
constexpr int M = 100;

vi x;
ll a, b;
ll ans, n;
ll dp[12][110][110][110];

// 앞으로 ind개를 골라 interesting하게 만드는 수
ll getDp(int n, int target, int mod, int sum) {
    if (sum < 0) return 0;
    if (n == 0) return (mod == 0 && sum == 0);

    ll& ref = dp[n][target][mod][sum];
    if (ref != -1) return ref;

    ref = 0;
    FOR(i, 0, 10) {
        if (sum - i < 0) continue;
        ref += getDp(n - 1, target, mod * i % target, sum - i);
    }

    return ref;
}

ll solve(ll num) {
    ll res = 0;

    if (num == 0) return 0;

    x.clear();
    while (num) {
        x.push_back(num % 10);
        num /= 10;
    }
    reverse(x.begin(), x.end());

    int l = x.size();

    FOR_(len, 1, l) {
        if (len == l) {
            ll pmod = 1;
            ll psum = 0;
            FOR(i, 0, l) {
                // leading zero를 원하지 않기 때문에 첫번째 것만 1부터 선택
                FOR_(first, i == 0 ? 1 : 0, x[i] - 1) {
                    // 다음 것들은 아무렇게나 골라도 됨
                    FOR_(sum, 1, 9 * len) {
                        res += getDp(l - 1 - i, sum, pmod * first % sum, sum - psum - first);
                    }
                }
                pmod *= x[i];
                psum += x[i];
            }
            // cout << pmod << ' ' << psum << '\n';
            if (pmod % psum == 0) res++;
        } else {
            FOR_(sum, 1, 9 * len) {
                FOR_(first, 1, 9) {
                    res += getDp(len - 1, sum, first % sum, sum - first);
                }
            }
        }
    }

    return res;
}

ll brute(int x) {
    auto f = [](ll x) {
        ll sum = 0;
        ll prod = 1;
        while (x) {
            ll d = x % 10;
            prod *= d;
            sum += d;
            x /= 10;
        }

        return (prod % sum) == 0;
    };

    ll res = 0;
    FOR_(i, 1, x) {
        res += f(i);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> a >> b;
        ans = 0;

        if (b == 1000000000000) {
            ans++;
            b--;
        }

        //cout << brute(b) << ' ' << brute(a - 1) << '\n';
        //cout << solve(b) << ' ' << solve(a - 1) << '\n';

        ans += solve(b);
        ans -= solve(a - 1);

        cout << "Case #" << caseNum << ": ";
        cout << ans << '\n';
    }

    return 0;
}