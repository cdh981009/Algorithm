#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

#define int long long
using ll = long long;
using pii = pair<int, int>;

int root[50];
int sz[50];
int arr[100000];
int n, m, p, k, a, b, c;

struct tup {
    int w, x, y;
};

vector<int> nums;
vector<tup> edges;
vector<tup> msts;

int find(int x) {
    return root[x] == x ? x : find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    root[y] = x;
    sz[x] += sz[y];
}

void getMst() {
    nums.push_back(0);
    nums.push_back(1e8);
    FOR(i, 0, m) {
        FOR(j, i, m) {
            int x = (edges[i].w + edges[j].w);
            if (x % 2)
                nums.push_back(x / 2 + 1);
            nums.push_back(x / 2);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (auto x : nums) {
        FOR(i, 0, n) {
            root[i] = i;
            sz[i] = 1;
        }

        int cnt = 0;
        
        sort(edges.begin(), edges.end(), [&x](const auto l, const auto r) {
            return abs(l.w - x) == abs(r.w - x) ? l.w > r.w : abs(l.w - x) < abs(r.w - x);
        });

        int cw, cl, cr;
        cw = cl = cr = 0;
        for (auto &[w, u, v] : edges) {
            if (!same(u, v)) {
                unite(u, v);
                cnt++;
                cw += abs(w - x);
                if (w > x) cr++;
                else cl++;
            }
            if (cnt == n - 1) break;
        }

        msts.push_back({cw, cl, cr});
    }
}

int query(int q) {
    auto it = upper_bound(nums.begin(), nums.end(), q);
    --it;
    int ind = it - nums.begin();
    int diff = q - *it;
 
    int res = msts[ind].w;
    //cout << q << ' ' << msts[ind].x << ' ' << msts[ind].y << '\n';
    res += msts[ind].x * diff;
    res -= msts[ind].y * diff;
 
    return res;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, u, v});
    }

    getMst();

    cin >> p >> k >> a >> b >> c;
    FOR(i, 0, p) {
        cin >> arr[i];
    }

    int ans = 0;
    int prev;
    FOR(i, 0, k) {
        int x;
        if (i < p) {
            x = arr[i];
        } else {
            x = (prev * a + b) % c;
        }
        ans ^= query(x);
        //if (i < 10)
        //cout << x << ' ' << query(x) << '\n';
        prev = x;
    }

    cout << ans << '\n';

    return 0;
}