// 13537: 수열과 쿼리 1
// https://www.acmicpc.net/problem/13537
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 101010;

int n, m;
int arr[N];

int segN;
vector<vector<int>> seg;

// merge sort tree
void constructTree() {
    for (segN = 1; segN <= n; segN <<= 1)
        ;
    seg.resize(2 * segN);
    FOR(i, 0, n) {
        seg[i + segN].push_back(arr[i]);
    }
    for (int i = segN - 1; i >= 1; --i) {
        seg[i].resize(seg[2 * i].size() + seg[2 * i + 1].size());
        merge(seg[2 * i].begin(),     seg[2 * i].end(),
              seg[2 * i + 1].begin(), seg[2 * i + 1].end(),
              seg[i].begin());
    }
}

int query(int x, int y, int k) {
    int res = 0;

    x += segN;
    y += segN;
    while (x <= y) {
        if (x % 2 == 1) {
            res += seg[x].end() - upper_bound(seg[x].begin(), seg[x].end(), k);
            x++;
        }
        if (y % 2 == 0) {
            res += seg[y].end() - upper_bound(seg[y].begin(), seg[y].end(), k);
            y--;
        }
        x /= 2;
        y /= 2;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    constructTree();

    cin >> m;
    FOR(i, 0, m) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;
        y--;
        cout << query(x, y, k) << '\n';
    }

    return 0;
}