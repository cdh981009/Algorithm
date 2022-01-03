#include <bits/stdc++.h>

using namespace std;

#define INF 6e4
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4 + 20;

using ll = long long;

int n;
int p[N];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        
        memset(p, -1, sizeof(int) * (n + 1));

        int st = 1;
        bool f = true;
        int l;
        int prev;

        FOR(i, 0, 2 * n) {
            cout << "? " << st << '\n';
            cout.flush();

            int x;
            cin >> x;

            if (f) {
                f = false;
                l = x;
            } else {
                p[prev] = x;
                if (x == l) {
                    FOR_(j, 1, n) {
                        if (p[j] == -1) {
                            st = j;
                            f = true;
                            break;
                        }
                    }
                    if (!f)
                        break;
                }
            }
            
            prev = x;

            if (x == 0)
                return 0;
        }

        cout << "! ";
        FOR_(i, 1, n) {
            cout << p[i] << ' ';
        }
        cout << '\n';
        cout.flush();
    }

    return 0;
}