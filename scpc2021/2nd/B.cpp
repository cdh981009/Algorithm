#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e8;

int k;
ll ans;
int x[8], y[8], perm[8];
vector<int> px, py;

ll dx(int cx) {
    ll ret = 0;
    FOR(i, 0, 8) {
        ret += abs(px[i] + cx - x[perm[i]]);
    }

    return ret;
}

ll dy(int cy) {
    ll ret = 0;
    FOR(i, 0, 8) {
        ret += abs(py[i] + cy - y[perm[i]]);
    }

    return ret;
}

int main(int argc, char** argv) {
    int T, tc;

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> k;
        px = {0, k, 2 * k, 3 * k, 3 * k, 2 * k, k, 0};
        py = {0, k, k, 0, -1 * k, -2 * k, -2 * k, -1 * k};

        FOR(i, 0, 8) {
            cin >> x[i] >> y[i];
            perm[i] = i;
        }
        ans = INF;

        do {
            // x
            ll a = INF;
            FOR(i, 0, 8) {
                ll cx = x[perm[i]] - px[i];
                a = min(a, dx(cx));
            }

            // y
            ll b = INF;
            FOR(i, 0, 8) {
                ll cy = y[perm[i]] - py[i];
                b = min(b, dy(cy));
            }

            ans = min(a + b, ans);
        } while (next_permutation(perm, perm + 8));

        cout << "Case #" << tc + 1 << endl;
        cout << ans << endl;
    }

    return 0;
}