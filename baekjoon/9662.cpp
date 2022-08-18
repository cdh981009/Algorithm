#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 22;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

ll m, k, a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> k;
    rep(i, 0, k) cin >> a[i];

    int mx = a[k - 1];

    // simulate
    vector<bool> vec;
    vec.push_back(0);
    ll end = (1 << (mx)) + mx;

    rep(i, 1, end) {
        bool z = false;
        rep(j, 0, k) {
            int l = i - a[j];
            if (l < 0) continue;
            if (vec[l] == 0) {
                z = true;
                break;
            }
        }

        if (z) {
            vec.push_back(true);
        }
        else {
            vec.push_back(false);
        }
    }

    int o = end - mx;
    int len = -1;
    int lenCnt = 0;
    for (int i = end - 1 - mx; i >= 0; --i) {
        bool p = true;

        rep(l, 0, mx) {
            if (vec[i + l] != vec[o + l]) {
                p = false;
                break;
            }
        }

        if (p) {
            len = o - i;
            rep(j, i, i + len) {
                if (vec[j] == 0) lenCnt++;
            }
            break;
        }
    }

    // 주기 len
    ll ans = 0;

    if (m <= end - 1) {
        rep_(i, 1, m) {
            if (vec[i] == 0) ans++;
        }
    } else {
        rep_(i, 1, end - 1 - mx) {
            if (vec[i] == 0) ans++;
        }
        m -= end - 1 - mx;
        int mr = m % len;
        int mq = m / len;
        ans += mq * lenCnt;
        rep(i, o - len, o - len + mr) {
            if (vec[i] == 0) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}