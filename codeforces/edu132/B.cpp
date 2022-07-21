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

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll arr[N], pre[N], suf[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep_(i, 1, n) cin >> arr[i];
    rep_(i, 1, n) {
        pre[i] = (arr[i] > arr[i+1] ? arr[i] - arr[i+1] : 0) + pre[i-1];
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i+1] + (arr[i] > arr[i-1] ? arr[i] - arr[i-1] : 0);
    }
    rep(i, 0, m) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << pre[t-1] - pre[s-1];
        } else {
            cout << suf[t+1] - suf[s+1];
        }
        cout << '\n';
    }

    return 0;
}