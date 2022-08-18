#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
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
constexpr int M = 100;

ll n, m, k, q;
ll a[N];

struct Q {
    int i, k, ind;
    bool operator<(const Q &o) {
        return this->k < o.k;
    }
};

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
        cin >> n >> q;
        vector<int> w(n, 0);
        vector<int> ans(q);

        rep(i, 0, n) cin >> a[i];

        deque<int> b;

        rep(i, 0, n) {
            b.push_back(i);
        }

        vector<Q> qs;
        rep(j, 0, q) {
            int i, k;
            cin >> i >> k;
            i--;
            qs.push_back({i, k, j});
        }
        sort(qs.begin(), qs.end());

        int j = -1;
        rep_(i, 1, n) {
            int x = b[0];
            int y = b[1];
            b.pop_front();
            b.pop_front();
            if (a[x] > a[y]) swap(x, y);
            // x lose, y win
            w[y]++;
            b.push_front(y);
            b.push_back(x);
            
            while (j + 1 < q && qs[j + 1].k <= i) {
                j++;
                ans[qs[j].ind] = w[qs[j].i];
            }
        }

        vector<int> bInd(n);
        rep(i, 0, n) {
            bInd[b[i]] = i;
        }

        while (j + 1 < q) {
            j++;
            auto [i, k, ind] = qs[j];
            int res = w[i];
            k -= n;
            if (b.front() == i) res += k;

            ans[ind] = res;
        }

        rep(i, 0, q)
            cout << ans[i] << '\n';
    }

    return 0;
}