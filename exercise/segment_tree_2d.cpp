#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
constexpr int N = 1 << 20;
int rows, cols;
int segTree[64][N];

int query1D(int r, int c1, int c2) {
    c1 += cols;
    c2 += cols;
    int s = 0;
    while (c1 <= c2) {
        if (c1%2 == 1) s += segTree[r][c1++];
        if (c2%2 == 0) s += segTree[r][c2--];
        c1 /= 2; c2 /= 2;
    }
    return s;
}

int query(int r1, int r2, int c1, int c2) {
    r1 += rows;
    r2 += rows;
    int s = 0;
    while (r1 <= r2) {
        if (r1%2 == 1) s += query1D(r1++, c1, c2);
        if (r2%2 == 0) s += query1D(r2--, c1, c2);
        r1 /= 2; r2 /= 2;
    }
    return s;
}

inline int power2RoundUp(int x) {
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;
    return x;
}

void update(int r, int c, int x) {
    segTree[r + rows][c + cols] = x;
    // leaf
    for (int i = (c + cols)/2; i >= 1; i /= 2) {
        segTree[r + rows][i] = segTree[r + rows][i<<1] + segTree[r + rows][(i<<1)|1];
    }
    // non-leaf
    for (int i = (r + rows)/2; i >= 1; i /= 2) {
        for (int j = (c + cols); j >= 1; j /= 2) {
            segTree[i][j] = segTree[i<<1][j] + segTree[(i<<1)|1][j];
        }
    }
}

void init(const vector<vector<int>>& v) {
    rows = power2RoundUp(v.size());
    cols = power2RoundUp(v[0].size());
    FOR(i, 0, rows) {
        FOR(j, 0, cols) {
            segTree[i + rows][j + cols] = ((i < v.size()) && (j < v[0].size())) ? v[i][j] : 0; 
        }
    }

    // leaf
    FOR(i, 0, rows) {
        for (int j = cols - 1; j > 0; --j) {
            segTree[i + rows][j] = segTree[i + rows][j<<1] + segTree[i + rows][(j<<1)|1];
        }
    }

    // non-leaf
    for (int i = rows - 1; i > 0; --i) {
        for (int j = 1; j <= 2*cols - 1; ++j) {
            segTree[i][j] = segTree[i<<1][j] + segTree[(i<<1)|1][j];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r , c; cin >> r >> c;
    vector<vector<int>> arr(r, vector<int>(c));
    FOR(i, 0, r) {
        FOR(j, 0, c) {
            int num; cin >> num;
            arr[i][j] = num;
        }
    }
    init(arr);
    update(1, 1, 0);
    cout << query(0, 1, 0, 1) << endl;
    cout << query(1, 1, 1, 2) << endl;
    
    return 0;
}