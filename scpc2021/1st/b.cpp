#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 50010;

int n, t;
string ans;
string str;

int main(int argc, char** argv) {
    int T, tc;
    
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n >> t >> str;
        ans = string(n, '-');

        // fix zero
        FOR(i, 0, n) {
            char c = str[i];
            if (c == '0') {
                int l = i - t;
                int r = i + t;
                if (l >= 0) {
                    ans[l] = '0';
                }
                if (r < n) {
                    ans[r] = '0';
                }
            }
        }

        // choose minimum one
        FOR(i, 0, n) {
            char c = str[i];
            if (c == '1') {
                int l = i - t;
                int r = i + t;
                if (l < 0) {
                    ans[r] = '1';
                } else if (r >= n) {
                    ans[l] = '1';
                } else {
                    if (ans[l] == '0') {
                        ans[r] = '1';
                    } else if (ans[r] == '0') {
                        ans[l] = '1';
                    } else if (ans[l] != '1' && ans[r] != '1') {
                        ans[r] = '1';
                    }
                }
            }
        }

        // fill remaining
        FOR(i, 0, n) {
            if (ans[i] == '-')
                ans[i] = '0';
        }

        cout << "Case #" << tc + 1 << '\n';
        cout << ans << '\n';
    }

    return 0;
}