#include <bits/stdc++.h>

using namespace std;

#define INF ((int)(1e9 + 7))
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

constexpr int N = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in, ex, rem;
    cin >> in >> ex;
    rep(i, 0, in.size()) {
        rem.push_back(in[i]);
        if (rem.size() >= ex.size()) {
            bool p = true;
            rep(j, 0, ex.size()) {
                if (rem[rem.size() - ex.size() + j] != ex[j]) {
                    p = false;
                    break;
                }
            }
            if (p) {
                rep(j, 0, ex.size())
                    rem.pop_back();
            }
        }
    }

    if (rem.empty()) rem = "FRULA";

    cout << rem << '\n';

    return 0;
}