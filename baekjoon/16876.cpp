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

int dp[10101][101];
string o;
int mm;

int getDp(string& n, int m) {
    if (m == 0) return (stoi(n) > stoi(o)) ^ (mm % 2 == 1);

    int& ref = dp[stoi(n)][m];
    if (ref != -1) return ref;

    rep(i, 0, 4) {
        char x = n[i];
        char nxt = n[i] + 1;
        if (x == '9') nxt = '0';

        n[i] = nxt;
        int res = getDp(n, m - 1);
        n[i] = x;

        if (res == false) return ref = true;
    }

    return ref = false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    string n;
    cin >> n >> mm;
    o = n;

    bool res = getDp(n, mm);

    if (res)
        cout << "koosaga\n";
    else
        cout << "cubelover\n";

    return 0;
}