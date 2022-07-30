#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (ll i = (a); i >= (b); --i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "Yes" : "No") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<ll, ll>;
using mll = map<ll, ll>;

constexpr ll N = 301010;

ll n, m;
string str;
ll ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> str;
    bool pos = false;

    if (n % 2 == 1) {
        if (str[0] == 'B' || str[n - 1] == 'A')
            pos = true;
    } else {
        if (n == 2) {
            if (str[0] == str[1]) pos = true;
        } else {
            pos = true;
            if (str[0] == 'A' && str[n - 1] == 'B')
                pos = false;
        }
    }

    printYN(pos);

    return 0;
}