// 15927: 회문은 회문아니야!!
// https://www.acmicpc.net/problem/15927
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    bool allSame = true;
    char a = s[0];
    FOR(i, 1, s.size()) {
        if (s[i] != a) {
            allSame = false;
            break;
        }
    }

    if (allSame) {
        cout << -1 << '\n';
    } else {
        bool palindrome = true;
        FOR(i, 0, (s.size() + 1) / 2) {
            if (s[i] != s[s.size() - 1 - i]) {
                palindrome = false;
                break;
            }
        }

        cout << s.size() - (palindrome ? 1 : 0) << '\n';
    }

    return 0;
}