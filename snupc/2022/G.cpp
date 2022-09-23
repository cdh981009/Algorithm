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

constexpr int N = 201010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    ll zeros = 0;
    multiset<ll> st;

    rep(i, 0, n) {
        ll x;
        cin >> x;
        if (x == 0) zeros++;
        else st.insert(x);
    }

    rep(i, 0, q) {
        ll x, y;
        cin >> x >> y;
        if (y == 1) continue;
        vector<ll> vec;
        while (!st.empty() && *st.begin() <= x) {
            vec.push_back(y * (*st.begin()));
            st.erase(st.begin());
        }
        if (y == 0) {
            zeros += vec.size();
        } else {
            rep(j, 0, vec.size()) {
                st.insert(vec[j]);
            }
        }
    }

    rep(i, 0, zeros) cout << 0 << ' ';
    for (auto &x : st) cout << x << ' ';

    cout << '\n';

    return 0;
}