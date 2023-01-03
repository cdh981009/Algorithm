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
        map<int, vector<int>> b2inds;
        vector<bool> visited(n, false);
        set<int> st;
        rep(i, 0, n + 1) {
            st.insert(i);
        }

        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) {
            cin >> b[i];
            b2inds[b[i]].push_back(i);
        }
        cin >> m;
        map<int, int> xCnt;
        rep(i, 0, m) {
            ll x;
            cin >> x;
            xCnt[x]++;
        }

        bool pos = true;

        // base
        rep(i, 0, n) {
            if (b[i] > a[i]) pos = false;
        }

        if (pos) {
            for (auto& [v, inds] : b2inds) {
                int cnt = 0;
                bool counted = false;
                int prev = n + 10;
                for (int i = inds.size() - 1; i >= 0; --i) {
                    int idx = inds[i];
                    
                    st.erase(idx);
                    auto left = *st.upper_bound(idx);

                    if (left < prev) {
                        counted = false;
                    }

                    if (!counted) {
                        if (a[idx] != b[idx]) {
                            cnt++;
                            counted = true;
                        }
                    }

                    prev = idx;
                }

                if (cnt > xCnt[v]) {
                    pos = false;
                    break;
                }
            }
        }

        printYN(pos);
    }

    return 0;
}