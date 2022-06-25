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
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 251010;
constexpr int M = 100;

ll n, m, q, ans;
ll arr[N];

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
        ll mn, mx, mni, mxi;
        mx = 0;
        mn = INF;
        vl vec;

        bool up = false;
        rep(i, 0, n) {
            ll x, y, z, w;
            cin >> x;
            
            while (true) {
                if (vec.size() >= 2) {
                    y = *(vec.end() - 1);
                    z = *(vec.end() - 2);
                    if ((x < y && y < z) || (x > y && y > z)) {
                        vec.pop_back();
                        continue;
                    }
                }
                if (vec.size() >= 3) {
                    y = *(vec.end() - 1);
                    z = *(vec.end() - 2);
                    w = *(vec.end() - 3);

                    vl v = {x, y, z, w};
                    sort(v.begin(), v.end());
                    if ((v[0] == x && v[3] == w) || (v[0] == w && v[3] == x)) {
                        vec.pop_back();
                        vec.pop_back();
                        continue;
                    }
                }
                break;
            }

            vec.push_back(x);
        }

        //for (auto x : vec) {
        //    cout << x << ' ';
        //}
        ans = vec.size() - 1;

        cout << ans << '\n';
    }

    return 0;
}