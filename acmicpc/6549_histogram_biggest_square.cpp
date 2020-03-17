#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

long long biggestSquare(const vector<int>& squares, size_t start, size_t end) {
    if (end == start)
        return squares[start];
    size_t mid = (start + end) / 2;
    long long left = biggestSquare(squares, start, mid);
    long long right = biggestSquare(squares, mid + 1, end);
    long long middle = 0;
    int l, r; l = mid; r = mid + 1;
    int height = min(squares[l], squares[r]);
    while (true) {
        middle = max(middle, (long long)height * (r - l + 1));
        if (l == start && r == end) {
            break;
        } else if (l == start) {
            height = min(height, squares[++r]);
        } else if (r == end) {
            height = min(height, squares[--l]);
        } else {
            if (squares[l - 1] >= squares[r + 1])
                height = min(height, squares[--l]);
            else
                height = min(height, squares[++r]);
        }
    }
    return max(max(left, right), middle);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        vector<int> squares(n);
        FOR(i, 0, n) {
            int x; cin >> x;
            squares[i] = x;
        }
        cout << biggestSquare(squares, 0, squares.size() - 1) << endl;
    }
    return 0;
}