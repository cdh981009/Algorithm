#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 3010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    int s, e, t;
    s = e = (n + 1) / 2;
    bool front = n % 2;

    vpii log;

    // from input to [0, 1, ... , n-1] (reverse)
    rep(i, 0, n) {
        cin >> a[i]; a[i]--;
        if (a[i] == s) t = i;
    }

    auto op = [&](int x, int y) {
        if ((x == 0 && y == n) ||
            (x == y && (x == 0 || x == n))) return;

        log.push_back({x, y});
        int j = 0;
        rep(i, y, n) b[j++] = a[i];
        rep(i, x, y) b[j++] = a[i];
        rep(i, 0, x) b[j++] = a[i];
        swap(a, b);
    };

    if (front) {
        op(t, n);
    } else {
        op(0, t + 1);
    }

    int cnt = 0;
    while (++cnt <= n - 2) {
        int sz = e - s + 1;

        if (front) {
            rep(i, 0, n) {
                if (a[i] == s - 1) {
                    op(sz, i + 1);
                    s--;
                    break;
                }
            }
        } else {
            rep(i, 0, n) {
                if (a[i] == e + 1) {
                    op(i, n - sz);                    
                    e++;
                    break;
                }
            }
        }

        front ^= 1;

        // rep(i, 0, n) cout << a[i] << ' ';
        // cout << '\n';
    }

    reverse(log.begin(), log.end());

    cout << log.size() << '\n';
    for (auto& l : log) {
        l = {n - l.se, n - l.fi};
        if (l.fi == 0) cout << 2 << ' ' << l.se << '\n';
        else if (l.se == n) cout << 2 << ' ' << l.fi << '\n';
        else cout << 3 << ' ' << l.fi << ' ' << l.se << '\n';
    }

    return 0;
}