#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
string s1, s2;
bool chk[N];
int ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> s1 >> s2;
        ans = 0;
        memset(chk, false, sizeof(bool) * n);
        FOR(i, 0, n) {
            bool x = s1[i] == '1';
            bool y = s2[i] == '1';
            if (!x && !y) {
                ans++;
            } else if (x && y) {
                if (i > 0 && !chk[i - 1]) {
                    bool z = s1[i - 1] == '1';
                    bool w = s2[i - 1] == '1';
                    if (!z && !w) {
                        chk[i - 1] = true;
                        ans++;
                        continue;
                    }
                }
                if (i < n - 1 && !chk[i + 1]) {
                    bool z = s1[i + 1] == '1';
                    bool w = s2[i + 1] == '1';
                    if (!z && !w) {
                        chk[i + 1] = true;
                        ans++;
                        continue;
                    }
                }
            } else {
                ans += 2;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}