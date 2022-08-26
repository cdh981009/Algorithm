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

constexpr int N = 1010;
int a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s = 0;    
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[j];
        }

        int prev = -1;
        
        repr_(j, m-1, 0) {
            int x = a[j];

            x--;
            if (x >= prev) x++;

            prev = x;
        }

        s ^= prev;
    }

    if (s)
        cout << "koosaga\n";
    else
        cout << "cubelover\n";

    return 0;
}