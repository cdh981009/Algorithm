#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int X = 4 * N;

int n, q;
int arr[N];
ll ans, k;
ll seg[X][4];

ll f(ll x) {
    return (x * (x + 1)) / 2;
}

void update(int node, int nodeL, int nodeR, int x, int v) {
    if (nodeL == nodeR) {
        arr[x] = v;
        seg[node][0] = 0;
        seg[node][1] = 0;
        seg[node][2] = 0;
        seg[node][3] = 1;
        return;
    }

    ll m = (nodeL + nodeR) / 2;
    if (x <= m)
        update(2 * node, nodeL, m, x, v);
    else
        update(2 * node + 1, m + 1, nodeR, x, v);

    int l = 2 * node;
    int r = 2 * node + 1;

    if (arr[m] <= arr[m + 1]) {
        if (seg[l][3] && seg[r][3]) {
            seg[node][0] = 0;
            seg[node][1] = 0;
            seg[node][2] = 0;
            seg[node][3] = 1;
        } else if (seg[l][3]) {
            seg[node][0] = seg[r][0];
            seg[node][1] = m - nodeL + 1 + seg[r][1];
            seg[node][2] = seg[r][2];
            seg[node][3] = 0;
        } else if (seg[r][3]) {
            seg[node][0] = seg[l][0];
            seg[node][1] = seg[l][1];
            seg[node][2] = nodeR - m + seg[l][2];
            seg[node][3] = 0;
        } else {
            seg[node][0] = seg[l][0] + seg[r][0] + f(seg[l][2] + seg[r][1]);
            seg[node][1] = seg[l][1];
            seg[node][2] = seg[r][2];
            seg[node][3] = 0;
        }
    } else {
        seg[node][0] = seg[l][0] + seg[r][0] + f(seg[l][2]) + f(seg[r][1]);
        seg[node][1] = seg[l][3] ? m - nodeL + 1 : seg[l][1];
        seg[node][2] = seg[r][3] ? nodeR - m     : seg[r][2];
        seg[node][3] = 0;
    }
}

void query(int node, int nodeL, int nodeR, int ql, int qr) {
    if (qr < nodeL || nodeR < ql)
        return;

    if (ql <= nodeL && nodeR <= qr) {
        ans += seg[node][0];

        if (seg[node][3]) {
            if (arr[nodeL - 1] <= arr[nodeL]) {
                k += nodeR - nodeL + 1;
            } else {
                ans += f(k);
                k = nodeR - nodeL + 1;
            }
        } else {
            if (arr[nodeL - 1] <= arr[nodeL]) {
                ans += f(k + seg[node][1]);
            } else {
                ans += f(k) + f(seg[node][1]);
            }
            k = seg[node][2];
        }

        return;
    }

    ll m = (nodeL + nodeR) / 2;
    query(2 * node, nodeL, m, ql, qr);
    query(2 * node + 1, m + 1, nodeR, ql, qr);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    FOR_(i, 1, n) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    FOR(i, 0, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
        } else {
            int l, r;
            cin >> l >> r;
            ans = k = 0;
            query(1, 1, n, l, r);
            cout << ans + f(k) << '\n';
        }
    }
    return 0;
}