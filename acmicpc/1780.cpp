#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
int a, b, c;

void cut(vector<vector<int>>& p, int x, int y, int n) {
    int ac = 0;
    int bc = 0;
    int cc = 0;

    FOR(i, x, x+n)
        FOR(j, y, y+n)
            (ac += (p[i][j] == -1)), (bc += (p[i][j] == 0)), (cc += (p[i][j] == 1));
    if (ac == n*n) {
        a++;
    } else if (bc == n*n) {
        b++;
    } else if (cc == n*n) {
        c++;
    } else {
        FOR(i, 0, 3)
            FOR(j, 0, 3)
                cut(p, x + i*n/3, y + j*n/3, n/3);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> paper(n, vector<int> (n));
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            int col; cin >> col;
            paper[i][j] = col;
        }
    }

    cut(paper, 0, 0, n);
    cout << a << "\n" << b << "\n" << c << "\n";
    return 0;
}