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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi vec;
    rep(i, 0, n) {
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.rbegin(), vec.rend());

    bool k = false;
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && vec[i] == vec[j]) {
            j++;
        }
        int cnt = j - i;

        if (cnt % 2 == 1) {
            k = true;
            break;
        }

        i = j;
    }

    if (k) cout << "koosaga\n";
    else cout << "cubelover\n";

    return 0;
}