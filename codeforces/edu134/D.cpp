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

constexpr int N = 101010;
constexpr int X = 30;

ll n, m, k, q, ans;
ll a[N], b[N], ax[N], bx[N];

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
        ans = (1LL << X) - 1;

        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];

        vector<pii> segs;
        segs.push_back({0, n - 1});

        for (int i = X; i > 0; --i) {
            int ind = i;
            bool pos = true;
            vector<pii> newSeg;

            for (auto &[s, e] : segs) {
                if (s > e) continue;

                int ac, bc, anc, bnc;
                ac = bc = anc = bnc = 0;

                rep_(i, s, e) {
                    if ((a[i] >> (ind - 1)) & 1) {
                        ax[s + ac] = a[i];
                        ac++;
                    } else {
                        ax[e - anc] = a[i];
                        anc++;
                    }

                    if ((b[i] >> (ind - 1)) & 1) {
                        bx[e - bc] = b[i];
                        bc++;
                    } else {
                        bx[s + bnc] = b[i];
                        bnc++;
                    }
                }

                if (ac == bnc) {
                    rep_(i, s, e) {
                        a[i] = ax[i];
                        b[i] = bx[i];
                    }

                    newSeg.push_back({s, s + ac - 1});
                    newSeg.push_back({s + ac, e});
                } else {
                    ans &= (((1LL << X) - 1) - (1 << (ind - 1)));
                    pos = false;
                    break;
                }
            }

            if (pos)
                swap(segs, newSeg);
        }

        cout << ans << '\n';
    }

    return 0;
}