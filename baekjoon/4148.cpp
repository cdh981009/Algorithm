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

int dp[32][5][5][5][5][5][5];

int getDp(int x, vector<int>& c) {
    if (x == 0) return false;

    int& ref = dp[x][c[0]][c[1]][c[2]][c[3]][c[4]][c[5]];
    if (ref != -1) return ref;

    rep(i, 0, 6) {
        if (x - i - 1 >= 0 && c[i] > 0) {
            c[i]--;
            int res = getDp(x - i - 1, c);
            c[i]++;

            if (res == false) return ref = true;
        }
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

    string str;
    while (getline(cin, str)) {
        int n = str.size();
        int s = 31;
        vector<int> cnt(6, 4);
        rep(i, 0, n) {
            int x = str[i] - '0';
            s -= x;

            cnt[x - 1]--;
        }
        int ans = getDp(s, cnt);
        char a = 'A', b = 'B';
        if (n % 2) swap(a, b);
        cout << str << ' ' << (ans ? a : b) << '\n';
    }

    return 0;
}