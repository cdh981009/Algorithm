#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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
ll arr[N];

bool solve() {
    bool moreThan3 = false;
    ll sum = 0;
    rep(i, 0, k) {
        ll x = arr[i] / m;
        if (x < 2) continue;
        if (x >= 3) moreThan3 = true;
        sum += x;
    }

    if (sum < n) return false;
    
    if (n % 2) {
        if (!moreThan3) return false;
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        rep(i, 0, k) cin >> arr[i];
        bool pos = false;

        pos |= solve();
        swap(n, m);
        pos |= solve();

        printYN(pos);
    }

    return 0;
}