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

vector<pii> vec;
vector<bool> ans;

bool dp[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, s;
    cin >> n;
    s = 0;

    rep(i, 0, n) {
        ll x; cin >> x;
        vec.push_back({x, i});
    }

    sort(vec.begin(), vec.end());

    dp[0] = false;
    rep(i, 1, N) {
        int j = 1;
        dp[i] = false;
        while (i - j * j >= 0) {
            if (dp[i - j * j] == false) {
                dp[i] = true;
                break;
            }
            j++;
        }
    }
    
    ans.resize(n);
    for (auto &[f, s] : vec) {
        ans[s] = dp[f];
    }

    for (auto p : ans) {
        cout << (p ? "koosaga" : "cubelover") << '\n';
    }

    return 0;
}