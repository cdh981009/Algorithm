#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, C;
    cin >> n >> C;
    vl v(C + 10, 0);
    FOR(i, 0, n) {
        ll c, d, h;
        cin >> c >> d >> h;
        v[c] = max(v[c], d * h);
    }

    cin >> m;
    vl w(m);
    FOR(i, 0, m) {
        ll d, h;
        cin >> d >> h;
        w[i] = {d * h};
    }

    // 돈을 x만큼 지불할 때 얻을 수 있는 최대 d * h * x
    vl bst(C + 10, 0);
    FOR(i, 1, v.size()) {
        ll c = i;
        for (int j = 1; j * c <= C; j++) {  // j = 고용갯수
            ll val = v[c] * j;
            ll cost = c * j;
            bst[cost] = max(bst[cost], val);
        }
    }

    // prefix max: 돈을 이만큼 지불하면 최대 이정도의 value를 얻는다
    FOR(i, 1, bst.size()) {
        bst[i] = max(bst[i], bst[i - 1]);
    }

    // monotonically increasing -> use binary search

    rep(i, 0, m) {
        ll x = w[i];
        if (bst[C] <= x) cout << -1 << ' ';
        else {
            auto it = upper_bound(bst.begin(), bst.begin() + C + 1, x);
            cout << (it - bst.begin()) << ' ';
        }
    }
    cout << '\n';

    return 0;
}