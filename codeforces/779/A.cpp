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

ll n, m, ans;

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
        cin >> n;
        string str; cin >> str;
        int cnt = 0;
        int ans = 0;
        FOR(i, 0, n) {
            if (i - 1 >= 0 && str[i-1] == '0' && str[i] == '0') ans += 2;
            if (i - 2 >= 0 && str[i-2] == '0' && str[i-1] == '1' && str[i] == '0') ans += 1;
        }

        cout << ans << '\n';

    }

    return 0;
}