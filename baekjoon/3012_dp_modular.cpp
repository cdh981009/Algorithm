// https://www.acmicpc.net/problem/3012
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 210;
constexpr int M = 100000;

using ll = long long;

int n;
ll dp[N][N];
bool of[N][N];
string str;

bool getOf(int s, int e) {
    if (s > e)
        return false;
    return of[s][e];
}

ll getDp(int s, int e) {
    if (s > e)
        return 1;
    char sc = str[s];
    if (sc == ')' || sc == '}' || sc == ']')
        return 0;

    ll& ref = dp[s][e];
    if (ref != -1)
        return ref;

    ref = 0;

    auto match = [](char l, char r) {     
        if (r == '?')
            return true;   
        if (l == '?' && (r == ')' || r == '}' || r == ']')) {
            return true;
        }
        if ((l == '(' && r == ')') ||
            (l == '{' && r == '}') ||
            (l == '[' && r == ']')) {
                return true;
        }
        return false;        
    };

    for (int i = s + 1; i <= e; i += 2) {
        char ec = str[i];
        if (match(sc, ec)) {
            ll x = getDp(s + 1, i - 1);
            ll y = getDp(i + 1, e);
            if (sc == '?' && ec == '?')
                x *= 3;
            if ((!getOf(s + 1, i - 1) && x == 0) || (!getOf(i + 1, e) && y == 0))
                continue;
            if (getOf(s + 1, i - 1) || getOf(i + 1, e))
                of[s][e] = true;
            ref += x * y;
            if (ref >= M)
                of[s][e] = true;
            ref %= M;
        }
    }

    return ref;
}

void solve() {
    cin >> n >> str;
    if (n % 2 == 1) {
        cout << 0 << '\n';
        return;
    }
    memset(dp, -1, sizeof(ll) * N * N);
    ll ans = getDp(0, n - 1);

    if (of[0][n - 1]) {
        string s;
        s.resize(5);
        FOR(i, 0, 5) {
            int x = ans % 10;
            ans /= 10;
            s[4 - i] = x + '0';
        }
        cout << s << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}