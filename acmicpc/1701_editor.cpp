// 1701: Editor
// https://www.acmicpc.net/problem/1701
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// modified KMP

int getPi(const string& p) {
    int ans = 0;

    int n = p.length();
    vector<int> pi(n, 0);

    FOR(s, 0, n) {
        int match = 0;
        FOR(i, 1, n - s) {
            while (match > 0 && p[s + i] != p[s + match])
                match = pi[match - 1];
            if (p[s + i] == p[s + match])
                match++;
            pi[i] = match;

            ans = max(ans, match);
        }
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    cout << getPi(str) << '\n';

    return 0;
}