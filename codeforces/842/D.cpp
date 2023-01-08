#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N], b[N];

vector<int> sz(N + 1);
vector<int> root(N + 1);

int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] < sz[y])
        swap(x, y);

    root[y] = x;
    sz[x] += sz[y];
}

int size(int x) {
    return sz[find(x)];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];

        vector<int> go(n + 1, -1);

        rep(i, 0, n + 1) {
            root[i] = i;
            sz[i] = 1;
        }

        rep(i, 0, n) {
            int x = a[i];
            go[x] = x - 1;
            unite(x, a[go[x]]);
        }

        ll cnt = 0;
        set<int> st;

        rep(i, 0, n) {
            int group = find(i + 1);
            if (!st.count(group)) {
                st.insert(group);
                cnt += size(group) - 1;
            }
        }
        ans = cnt + 1;

        rep(i, 0, n) {
            int x = a[i];
            if (x == n) continue;

            // want to go to index x
            if (x == i) ans = min(ans, cnt);

            int y = a[x];

            if (same(x, y)) {
                ans = min(ans, cnt - 1);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}