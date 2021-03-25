// 1509: 팰린드롬 분할
// https://www.acmicpc.net/problem/1509
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2500;
int n;
int palin[N][N];
int dp[N];
string str;

bool isPalin(int s, int e) {
    if (s == e)
        return true;
    if (s + 1 == e)
        return str[s] == str[e];

    int &ref = palin[s][e];
    if (ref != - 1)
        return ref;

    return ref = (str[s] == str[e]) && isPalin(s + 1, e - 1);
}

int divide(int s) {
    if (s == n)
        return 0;

    if (s == n - 1)
        return 1;

    int& ref = dp[s];

    if (ref != -1)
        return ref;

    ref = INF;

    FOR(e, s, n) {
        if (isPalin(s, e)) {
            ref = min(ref, divide(e + 1) + 1);
        }
    }

    return ref;
}



int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(palin, -1, sizeof(int) * N * N);
    memset(dp, -1, sizeof(int) * N);

    cin >> str;
    n = str.size();

    cout << divide(0) << '\n';

    return 0;
}