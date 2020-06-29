#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n;
bool c[25][25];
bool check[25][25];

int dfs(int i, int j) {
    int cnt = 1;
    check[i][j] = true;
    const static vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto p : delta) {
        int x = i + p.first;
        int y = j + p.second;
        if (x >=0 && x < n && y >=0 && y < n && c[x][y] && !check[x][y])
            cnt += dfs(x, y);
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            char x; cin >> x;
            c[i][j] = x -'0';
        }
    }
    vector<int> sizes;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (!check[i][j] && c[i][j]) {
                sizes.push_back(dfs(i, j));
            }
        }
    }
    sort(sizes.begin(), sizes.end());
    cout << sizes.size() << "\n";
    for (auto num : sizes)
        cout << num << "\n";
    return 0;
}