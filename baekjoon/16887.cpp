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

constexpr int N = 1010101;

int dp[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, s, x;
    vll vec;
    s = 0;

    cin >> n;
    dp[0] = dp[1] = dp[2] = dp[3] = 0;

    rep(i, 0, n) {
        cin >> x;
        if (x > 3) vec.push_back(x);
    }
    sort(vec.begin(), vec.end());

    // fill dp range [0, N)
    map<int, int> cnt;
    set<int> notIn;

    cnt[0] = 1;
    rep(i, 1, N / 10) {
        notIn.insert(i);
    }

    ll i = 0, j = 0;

    rep(k, 4, N) {
        while ((i + 1) * (i + 1) <= k) {
            i++;
            x = dp[i];
            if (++cnt[x] == 1)
                notIn.erase(x);
        }
        
        while (j * j * j * j < k) {
            x = dp[j];
            if (--cnt[x] == 0)
                notIn.insert(x);
            j++;
        }

        dp[k] = *notIn.begin();
    }

    // find ans

    i = 0, j = 0;
    cnt.clear();
    notIn.clear();
    cnt[0] = 1;
    rep(i, 1, N / 10) {
        notIn.insert(i);
    }

    rep(k, 0, vec.size()) {
        ll num = vec[k];

        while ((i + 1) * (i + 1) <= num) {
            i++;
            x = dp[i];
            if (++cnt[x] == 1)
                notIn.erase(x);
        }
        
        while (j * j * j * j < num) {
            x = dp[j];
            if (--cnt[x] == 0)
                notIn.insert(x);
            j++;
        }

        // cout <<  *notIn.begin() << '\n';
        s ^= *notIn.begin();
    }

    //rep(i, 0, N)
    //    cout << i << ' ' << dp[i] << '\n';


    if (s == 0)
        cout << "cubelover\n";
    else
        cout << "koosaga\n";

    return 0;
}