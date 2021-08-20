// 1786
// https://www.acmicpc.net/problem/1786
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

vector<int> matches;

string str, ptrn;

void rabinKarp(const string& s, const string& p) {
    if (p.size() > s.size())
        return;

    ll sh[2] = {0, 0};
    ll ph[2] = {0, 0};
    ll m[2] = {1000000007, 999999937};
    ll b[2] = {31, 51};
    ll pw[2] = {1, 1};

    FOR(i, 0, p.size()) {
        FOR(j, 0, 2) {
            sh[j] = (sh[j] * b[j] + s[i]) % m[j];
            ph[j] = (ph[j] * b[j] + p[i]) % m[j];
            pw[j] = (pw[j] * b[j]) % m[j];
        }
    }

    FOR_(i, 0, s.size() - p.size()) {
        if (i != 0) {
            FOR(j, 0, 2) {
                sh[j] = (sh[j] * b[j]) % m[j];
                sh[j] = (sh[j] - (pw[j] * s[i - 1]) % m[j] + m[j]) % m[j];
                sh[j] = (sh[j] + s[i + p.size() - 1]) % m[j];
            }
        }

        if (sh[0] == ph[0] && sh[1] && ph[1]) {
            matches.push_back(i + 1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getline(cin, str);
    getline(cin, ptrn);

    rabinKarp(str, ptrn);
    cout << matches.size() << '\n';
    for (int x : matches)
        cout << x << ' ';
    cout << '\n';

    return 0;
}