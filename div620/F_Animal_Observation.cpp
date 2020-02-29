#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
constexpr int N = 1 << 20;
int rows;
int cols;
int segTree[51][N];

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

void updateRange(int r, int c, int k, int x) {
    FOR(i, c, c + k)
        segTree[r][i + cols] = x;
    
    int c1 = c + cols; 
    int c2 = c + k - 1 + cols;
    while (c1 > 1) {
        c1 /= 2; c2 /= 2;
        FOR_(i, c1, c2) {
            segTree[r][i] = segTree[r][i*2] + segTree[r][i*2+1];
        }
    }
}

int query(int r, int c1, int c2) {
    c1 += cols; c2 += cols;
    int s = 0;
    while (c1 <= c2) {
        if (c1%2 == 1) s += segTree[r][c1++];
        if (c2%2 == 0) s += segTree[r][c2--];
        c1 /= 2; c2 /= 2;
    }
    return s;
}

void init(const vector<vector<int>>& v) {
    cols = power2RoundUp(v[0].size());
    rows = v.size();
    FOR(i, 0, rows)
        FOR(j, 0, cols)
            segTree[i][j + cols] = (j < v[0].size()) ? v[i][j] : 0; 

    FOR(i, 0, rows)
        for (int j = cols-1; j >= 1; --j)
            segTree[i][j] = segTree[i][j*2] + segTree[i][j*2+1];
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> arr(n + 1, vector<int>(m, 0));
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            int x; cin >> x;
            arr[i][j] = x;
        }
    }
    init(arr);

    int animal = 0;
    FOR(i, 0, n) {
        int maxSum = -1;
        int maxInd = 0;
        FOR_(j, 0, m - k) {
            int sum = query(i, j, j+k-1) + query(i+1, j, j+k-1);
            if (maxSum < sum) {
                maxSum = sum;
                maxInd = j;
            }
        }
        animal += maxSum;
        updateRange(i+1, maxInd, k, 0);
    }
    cout << animal << "\n";
    return 0;
}