#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
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

bool visited[N];
int dist[N];
ll cnt[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    set<pair<int, int>> q;
    q.insert({0, n});
    visited[n] = true;
    cnt[n] = 1;

    auto op = [&](int x, int d, int c) {
        if (x < 0 || x >= N) return;

        if (q.count({d, x})) {
            cnt[x] += cnt[c];
        } else if (!visited[x]) {
            visited[x] = true;
            q.insert({d, x});
            cnt[x] = cnt[c];
        }
    };

    int ans = 0;
    while (!q.empty()) {
        auto it = q.begin();
        auto [d, c] = *it;
        q.erase(it);

        if (c == k) {
            ans = d;
        }

        op(c + 1, d + 1, c);
        op(c - 1, d + 1, c);
        op(c * 2, d + 1,c );
    }

    cout << ans << '\n' << cnt[k] << '\n';

    return 0;
}