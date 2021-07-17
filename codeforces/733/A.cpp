#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        string str; cin >> str;
        int ans = 0;
        FOR(i, 0, str.size()) {
            int x = str[i] - '0';
            ans = max(ans, x);
        }
        cout << ans << '\n';

    }
    return 0;
}