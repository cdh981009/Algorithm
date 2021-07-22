#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10;

bool ans;
int n, m;
string s, t;

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
        n = s.size();
        m = t.size();

        if (m <= n) {
            bool even = (m % 2 == 1);
            int si = 0;
            int ti = 0;
            while (si < n && ti < m) {
                if ((n - si - 1) % 2 != even) {
                    if (s[si] == t[ti]) {
                        even = !even;
                        ti++;
                    }
                }
                si++;
            }

            if (ti == m)
                ans = true;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
    return 0;
}