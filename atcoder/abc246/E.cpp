#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    pii a, b;
    cin >> a.fi >> a.se >> b.fi >> b.se;
    a.fi--;
    a.se--;
    b.fi--;
    b.se--;

    vector<vector<bool>> c(n, vector<bool>(n, false));
    vector<vector<int>> v(n, vector<int>(n, -1));

    rep(i, 0, n) {
        string str;
        cin >> str;
        rep(j, 0, n) {
            if (str[j] != '.')
                c[i][j] = true;
        }
    }

    bool pos = ((a.fi + a.se) % 2) == ((b.fi + b.se) % 2);
    int ans = 0;

    if (pos) {
        queue<pair<int, pii>> q;
        q.push({0, a});
        v[a.fi][a.se] = 0;

        while (!q.empty()) {
            auto pr = q.front();
            q.pop();

            auto pos = pr.se;
            auto dst = pr.first;

            int d;

            auto valid = [&](int x, int y) {
                return (x >= 0 && x < n && y >= 0 && y < n && !c[x][y]);
            };

            rep(i, 0, 4) {
                d = 1;
                while (true) {
                    int x = pos.fi + d * (i % 2 ? 1 : -1);
                    int y = pos.se + d * (i >= 2 ? 1 : -1);

                    if (!valid(x, y)) break;
                    if (v[x][y] != -1 && v[x][y] <= dst) break;

                    q.push({dst + 1, {x, y}});
                    v[x][y] = dst + 1;
                
                    d++;
                }
            }
        }
    }

    ans = v[b.fi][b.se];

    if (!pos) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}