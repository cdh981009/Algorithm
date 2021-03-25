#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int x; cin >> x;
            A[i][j] = x;
        }
    }
    cin >> m;
    int k; cin >> k;
    vector<vector<int>> B(m, vector<int>(k));
    FOR(i, 0, m) {
        FOR(j, 0, k) {
            int x; cin >> x;
            B[i][j] = x;
        }
    }

    vector<vector<int>> C(n, vector<int>(k, 0));
    FOR(i, 0, n)
        FOR(j, 0, k)
            FOR(l, 0, m)
                C[i][j] += A[i][l] * B[l][j];
    
    FOR(i, 0, n) {
        FOR(j, 0, k) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}