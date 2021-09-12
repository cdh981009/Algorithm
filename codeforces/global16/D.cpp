#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;


constexpr int N = 301;
int n, m;
int sn;
int ans;
int p[N * N], a[N * N];
int cnt[N * N];
int pre[N * N];
int seg[4 * N * N];

void update(int x, int v) {
    x += sn;
    seg[x] += v;
    while (x > 1) {
        x /= 2;
        seg[x] = seg[2 * x] + seg[2 * x + 1];
    }
}

int query(int a, int b) {
    a += sn;
    b += sn;
    int ret = 0;
    while (a <= b) {
        if (a % 2) {
            ret += seg[a++];
        }
        if (b % 2 == 0) {
            ret += seg[b--];
        }
        a /= 2;
        b /= 2;
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        for (sn = 1; sn < n * m; sn <<= 1)
            ;
        memset(seg, 0, sizeof(int) * 2 * sn);
        memset(pre, 0, sizeof(int) * n * m);
        memset(cnt, 0, sizeof(int) * n * m);

        FOR(i, 0, n * m) {
            cin >> p[i];
            a[i] = p[i];
        }

        sort(p, p + n * m);

        int up = unique(p, p + n * m) - p;
        FOR(i, 0, n * m) {
            a[i] = lower_bound(p, p + up, a[i]) - p;
            pre[a[i]]++;
            cnt[a[i]] = 0;
        }

        FOR(i, 1, n * m) {
            pre[i] += pre[i - 1];
        }

        ans = 0;
        FOR(i, 0, n * m) {
            int x = a[i] == 0 ? 0 : pre[a[i] - 1];
            x += cnt[a[i]]++;
            int r = x / m;

            ans += query(r * m, (a[i] == 0 ? 0 : pre[a[i] - 1]) -1);
            update(x, 1);
        }

        cout << ans << '\n';
    }
    return 0;
}