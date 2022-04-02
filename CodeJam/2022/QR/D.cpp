#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2001;
constexpr int M = 100;

ll n, k, m, ans;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    rep_(testcase, 1, tc) {
        cout << "Case #" << testcase << ": ";
        cin >> n;

        vl f(n + 1, 0), p(n + 1, 0), deg(n + 1, 0);
        vector<bool> visited(n + 1, false);
        priority_queue<pii> q;

        rep_(i, 1, n) cin >> f[i];
        rep_(i, 1, n) {
            cin >> p[i];
            deg[p[i]]++;
        }

        rep_(i, 1, n) {
            if (deg[i] == 0) {
                q.push({-f[i], i});
                visited[i] = true;
            }
        }
        visited[0] = true;

        ans = 0;
        while (!q.empty()) {
            auto pr = q.top();
            q.pop();

            int curr = pr.se;
            ll v = -pr.fi;

            int nxt = p[curr];
            if (visited[nxt]) {
                ans += v;
            } else {
                visited[nxt] = true;
                q.push({-max(v, f[nxt]), nxt});
            }
        }

        cout << ans << '\n';
    }

    return 0;
}