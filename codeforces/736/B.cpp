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
        cin >> n;
        cin >> s2 >> s1;
        ans = 0;
        FOR(i, 0, n) {
            if (s1[i] == '0')
                continue;
            if (s2[i] == '0') {
                ans++;
            } else if (i - 1 >= 0 && s2[i - 1] == '1') {
                ans++;
                s2[i - 1] = '2';
            } else if (i + 1 < n && s2[i + 1] == '1') {
                ans++;
                s2[i + 1] = '2';
            }
        }

        cout << ans << '\n';
    }
    return 0;
}