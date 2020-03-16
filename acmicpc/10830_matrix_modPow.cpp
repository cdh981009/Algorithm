#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
int MOD = 1000;
vector<vector<int>> I;
vector<vector<int>> operator*(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();

    vector<vector<int>> C(n, vector<int>(k));
    FOR(i, 0, n) {
        FOR(j, 0, k) {
            FOR(l, 0, m) {
                C[i][j] += A[i][l] * B[l][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

vector<vector<int>> matrixModPow(const vector<vector<int>>& A, long long b) {
    if (b == 0) return vector<vector<int>>(I);
    auto u = matrixModPow(A, b/2);
    u = u * u;
    if (b % 2 == 1) u = u * A;
    return u;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long b;
    cin >> n >> b;

    vector<vector<int>> A(n, vector<int>(n));
    I.assign(n, vector<int>(n, 0));
    FOR(i, 0, n) {
        FOR(j, 0, n){
            int x; cin >> x;
            A[i][j] = x;
            if (i == j) I[i][j] = 1;
        }
    }

    vector<vector<int>> C = matrixModPow(A, b);
    FOR(i, 0, n) {
        FOR (j, 0, n) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}