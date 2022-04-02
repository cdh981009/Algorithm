#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        string str; cin >> str;
        string ans = "";
        int open = 0;
        FOR(i, 0, str.length()) {
            int num = str[i] - '0';
            while (open > num) {
                ans.push_back(')');
                open--;
            }
            while (open < num) {
                ans.push_back('(');
                open++;
            }
            ans.push_back(str[i]);
        }
        while (open > 0) {
            ans.push_back(')');
            open--;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}