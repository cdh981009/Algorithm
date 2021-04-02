// 4792: Red/Blue Spanning Tree
// https://www.acmicpc.net/problem/4792
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 1010;

int root[N];
int n, m, k;

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;
    root[y] = x;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0)
            break;

        using pii = pair<int, int>;
        vector<pii> edgeB;
        vector<pii> edgeR;
        // m = O(n^2)
        FOR(i, 0, m) {
            char c;
            int f, t;
            cin >> c >> f >> t;
            f--; t--;
            if (c == 'R') {
                edgeR.push_back({f, t});
            } else {
                edgeB.push_back({f, t});
            }
        }

        // only use specific color
        auto mst = [](const vector<pii> &edge) -> int {
            FOR(i, 0, n) {
                root[i] = i;
            }
            int cnt = 0;
            for (auto& p : edge) {
                int a = p.first;
                int b = p.second;
                if (same(a, b))
                    continue;
                unite(a, b);
                cnt++;
            }
            return cnt;
        };

        int maxBlue = mst(edgeB);
        int minBlue = n - 1 - mst(edgeR);

        bool p = minBlue <= k && k <= maxBlue;
        cout << p << '\n';
    }

    return 0;
}