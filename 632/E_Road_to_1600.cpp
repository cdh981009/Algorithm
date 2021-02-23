#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int base[3][3] {
    1, 2, 5,
    7, 3, 4,
    8, 6, 9
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int x = n * n;
    if (n < 3) {
        cout << -1 << "\n";
    } else {
        vector<vector<int>> ans(n, vector<int>(n));
        int remain = x - 9;
        FOR(i, 0, 3) {
            FOR(j, 0, 3) {
                ans[i][j] = base[i][j] + remain;
            }
        }
        bool dl = true;
        for (int i = n; i > 3; --i) {
            FOR(j, 0, 2*i - 1) {
                if (j < i) {
                    ans[j][i - 1] = dl ? remain - j : remain - 2*i + 2 + j;
                } else {
                    ans[i - 1][2*i - j - 2] = dl ? remain - j : remain - 2*i + 2 + j;
                }
            }
            dl = !dl;
            remain -= 2*i - 1;
        }
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}