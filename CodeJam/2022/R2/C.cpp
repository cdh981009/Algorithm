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
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 11;
constexpr int M = 100;

ll n;
bool pos;
pll child[N];
pll candy[N];

bool took[N];
bool picked[N];

int order[N];
int choose[N];


bool solve(int ind) {
    if (ind == n) {
        return true;
    }

    FOR(i, 0, n) {
        if (!picked[i]) {
            picked[i] = true;
            order[ind] = i;

            vector<int> candies;
            ll minv = INT64_MAX;

            auto dist = [](int kid, int can) {
                ll x = child[kid].first - candy[can].first;
                ll y = child[kid].second - candy[can].second;
                return x * x + y * y;
            };

            FOR(j, 0, n + 1) {
                if (took[j]) continue;
                ll distres = dist(i, j);
                minv = min(minv, distres);
            }

            FOR(j, 0, n + 1) {
                if (took[j]) continue;
                ll distres = dist(i, j);
                if (distres == minv)
                    candies.push_back(j);
            }

            for (auto ci : candies) {
                if (ci == 0) continue;

                took[ci] = true;
                choose[ind] = ci;

                if (solve(ind + 1)) return true;

                took[ci] = false;
            }

            // pop
            picked[i] = false;
        }
    }

    return false;
}

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
        FOR(i, 0, n) {
            ll x, y;
            cin >> x >> y;
            child[i] = {x, y};
        }
        FOR(i, 0, n + 1) {
            ll x, y;
            cin >> x >> y;
            candy[i] = {x, y};
        }
        
        memset(picked, 0, sizeof(picked));
        memset(took, 0, sizeof(took));

        pos = solve(0);

        if (pos) {
            cout << "POSSIBLE" << '\n';
            FOR(i, 0, n) {
                cout << order[i] + 1 << ' ' << choose[i] + 1 << '\n';
            }
        }
        else
            cout << "IMPOSSIBLE" << '\n';

        // cout << brute(str) << '\n';
    }

    return 0;
}