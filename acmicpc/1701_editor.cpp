// 1701: Editor
// https://www.acmicpc.net/problem/1701
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// modified KMP

vector<int> getPi(const string& p, int s) {
    int n = p.length() - s;
    vector<int> pi(n, 0);

    int match = 0;
    FOR(i, 1, n) {
        while (match > 0 && p[s + i] != p[s + match])
            match = pi[match - 1];
        if (p[s + i] == p[s + match])
            match++;
        pi[i] = match;
    }

    return pi;
}

// modified kmp
int kmp(const string& str) {
    int n = str.length();

    int ret = 0;
    FOR(s, 1, n) {
        // new needle: str[s...]
        vector<int> pi = getPi(str, s);

        int maxMatch = 0;
        int match = 0;

        FOR(i, 0, n) {
            while (match > 0 && str[i] != str[s + match]) {
                match = pi[match - 1];
            }

            if (str[i] == str[s + match]) {
                match++;
            }

            if (match > maxMatch) {
                maxMatch = match;
            } else if (match == maxMatch) {
                ret = max(ret, maxMatch);
            }

            if (match == n - s) {
                match = pi[match - 1];
            }
        }
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    cout << kmp(str) << '\n';

    return 0;
}