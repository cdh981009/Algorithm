#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        int n; cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        int trace = 0;
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                int x; cin >> x;
                if (i == j) trace += x;
                mat[i][j] = x;
            }
        }
        int rowCnt = 0;
        int colCnt = 0;
        FOR(i, 0, n) {
            vector<int> rCnt(n, 0);
            vector<int> cCnt(n, 0);
            FOR(j, 0, n) {
                rCnt[mat[i][j] - 1]++;
                cCnt[mat[j][i] - 1]++;
            }
            FOR(k, 0, n) {
                if (rCnt[k] > 1) {
                    rowCnt++;
                    break;
                }
            }
            FOR(k, 0, n) {
                if (cCnt[k] > 1) {
                    colCnt++;
                    break;
                }
            }
        }
        cout << "Case #" << 
            t << ": " << 
            trace << " " <<
            rowCnt << " " <<
            colCnt << "\n";
    }
    return 0;
}