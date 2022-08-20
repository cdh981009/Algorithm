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

constexpr int N = 100;
constexpr int M = 100;

int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int cnt1 = 0;
    int s = 0;
    rep(i, 0, n) {
        int x;
        cin >> x;
        if (x == 1)
            cnt1++;
        
        s ^= x;
    }

    bool k = false;

    if (cnt1 == n) {
        if (cnt1 % 2 == 0)
            k = true;
        else
            k = false;
    } else {
        if (s == 0) {
            k = false;
        } else {
            k = true;
        }
    }

    if (k)
        cout << "koosaga\n";
    else
        cout << "cubelover\n";

    return 0;
}