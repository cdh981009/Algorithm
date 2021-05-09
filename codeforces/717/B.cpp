#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2010;

int n;
int pxor[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;

        pxor[0] = 0;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (i == 0)
                pxor[i] = x;
            else
                pxor[i] = pxor[i - 1] ^ x;
        }

        bool three = false;
        FOR(i, 0, n - 2) {
            FOR(j, i + 1, n - 1) {
                int x = pxor[j] ^ pxor[i];
                int y = pxor[i];
                int z = pxor[n - 1] ^ pxor[j];
                if (x == y && y == z) {
                    three = true;
                    break;
                }
            }
        }
        cout << (pxor[n - 1] == 0 || three ? "YES" : "NO") << '\n';
    }
    return 0;
}