#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 10;

int n;
string str;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> str;
        string ans;
        int end = 0;
        FOR(i, 1, n) {
            if (str[i] > str[i - 1])
                break;
            end = i;
        }

        if (n >= 2 && str[0] == str[1]) {
            ans.push_back(str[0]);
            ans.push_back(str[0]);
        } else {
            FOR_(i, 0, end) {
                ans.push_back(str[i]);
            }
            for (int i = end; i >=0; --i) {
                ans.push_back(str[i]);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}