#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1001;

int n;
string s, t;
bool ans;

bool solve(int i, int j, bool turned) {
    if (i < 0 || i >= s.size())
        return false;
    if (s[i] != t[j])
        return false;
    if (j == t.size() - 1)
        return true;
    if (!turned)
        return solve(i + 1, j + 1, false) | solve(i - 1, j + 1, true);
    else
        return solve(i - 1, j + 1, true);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ans = false;
        cin >> s >> t;
        
        FOR(i, 0, s.size()) {
            ans |= solve(i, 0, false);
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}