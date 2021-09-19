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
char str[N];

ll mod(ll x) {
    if (x >= M) return M + x % M;
    else return x;
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
            ll x = getDp(s + 1, i - 1) * getDp(i + 1, e);
            if (sc == '?' && ec == '?')
                x *= 3;
            ref += x;
            ref = mod(ref);
        }
    }

    return ref;
}

void solve() {
    scanf("%d%s", &n, str);
    if (n % 2 == 1) {
        printf("%d\n", 0);
        return;
    }
    memset(dp, -1, sizeof(dp));
    ll ans = getDp(0, n - 1);

    if (ans >= M) {
        printf("%05lld\n", ans - M);
    } else {
        printf("%d\n", ans);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}