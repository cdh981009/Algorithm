#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

string encode(vector<vector<bool>>& p, int x, int y, int n) {
    int wc = 0;
    int bc = 0;

    FOR(i, x, x+n)
        FOR(j, y, y+n)
            if (p[i][j]) bc++; 
            else wc++;
    string str;

    if (wc == n*n) {
        str = "0";
    } else if (bc == n*n) {
        str = "1";
    } else {
        str += "(";
        str += encode(p, x, y, n/2);
        str += encode(p, x, y+n/2, n/2);
        str += encode(p, x+n/2, y, n/2);
        str += encode(p, x+n/2, y+n/2, n/2);
        str += ")";
    }
    return str;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<bool>> paper(n, vector<bool> (n));
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            char col; cin >> col;
            paper[i][j] = col-'0';
        }
    }

    cout << encode(paper, 0, 0, n) << "\n";
    return 0;
}