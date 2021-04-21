#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2000;

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
        bool p = true;

        int lt = 0;
        int lm = 0;
        int rt = 0;
        int rm = 0;
        FOR(i, 0, n) {
            if (str[i] == 'T') {
                lt++;
            } else {
                lm++;
            }

            if (str[n - i - 1] == 'T') {
                rt++;
            } else {
                rm++;
            }

            if (lt < lm || rt < rm) {
                p = false;
                break;
            }
        }

        if (lt != 2 * lm)
            p = false;
        cout << (p ? "YES" : "NO") << '\n';
    }
    return 0;
}