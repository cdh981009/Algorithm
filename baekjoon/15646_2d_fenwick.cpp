// https://www.acmicpc.net/problem/15646
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 5050;

int n, m, q;
ll tree[N][N];

void upd(int x, int y, int d) {
    for (x++; x < N; x += (x & -x)) {
        for (int i = y + 1; i < N; i += (i & -i)) {
            tree[x][i] += d;
        }
    }
}

ll query(int x, int y) {
    ll sum = 0;
    for (x++; x > 0; x -= (x & -x)) {
        for (int i = y + 1; i > 0; i -= (i & -i)) {
            sum += tree[x][i];
        }
    }

    return sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;
    FOR(i, 0, q) {
        int t, x1, x2, y1, y2, d;
        cin >> t;
        if (t == 1) {
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            upd(x1, y1, d);
            upd(x2 + 1, y2 + 1, d);
            upd(x1 + 1, y2 + 1, -d);
            upd(x2 + 1, y1 + 1, -d);
        } else {
            cin >> x1 >> y1;
            cout << query(x1, y1) << '\n';
        }
    }

    return 0;
}