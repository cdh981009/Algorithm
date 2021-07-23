#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;
string str;
int cnt[27];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        memset(cnt, 0, sizeof(int) * 27);
        cin >> str;
        FOR(i, 0, str.size()) {
            int c = str[i] - 'a';
            cnt[c] = min(2, cnt[c] + 1);
        }
        int ans = 0;
        FOR(i, 0, 27) {
            ans += cnt[i];
        }
        ans /= 2;
        cout << ans << '\n';
    }
    return 0;
}