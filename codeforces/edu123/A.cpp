#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
constexpr int M = 1e9 + 7;

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
        string str; cin >> str;
        bool r, g, b;
        r = g = b = false;
        bool pos = true;
        FOR(i, 0, str.size()) {
            if (str[i] == 'R') {
                if (r == false) pos = false;
            } else if (str[i] == 'G') {
                if (g == false) pos = false;
            } else if (str[i] == 'B') {
                if (b == false) pos = false;
            } else if (str[i] == 'r') {
                r = true;
            } else if (str[i] == 'g') {
                g = true;
            } else {
                b = true;
            }
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }

    return 0;
}