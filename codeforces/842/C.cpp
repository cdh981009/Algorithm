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

constexpr int N = 301010;
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
        vector<int> cnt(n + 1, 0);
        vector<int> p(n, -1);
        vector<int> q(n, -1);
        set<int> phas, qhas;

        rep(i, 0, n) {
            phas.insert(i + 1);
            qhas.insert(i + 1);
        }

        bool pos = true;
        rep(i, 0, n) {
            int x;
            cin >> x;
            cnt[x]++;
            if (cnt[x] == 1) {
                p[i] = x;
                phas.erase(x);
            } else {
                q[i] = x;
                qhas.erase(x);
            }
            if (cnt[x] >= 3) pos = false;
        }

        if (pos) {
            vector<pair<int, int>> qneed;
            rep(i, 0, n) {
                if (p[i] != -1) {
                    qneed.push_back({p[i], i});
                }
            }
            sort(qneed.begin(), qneed.end());

            for (auto& [pval, i] : qneed) {
                if (*qhas.begin() > pval) {
                    pos = false;
                    break;
                } else {
                    q[i] = *qhas.begin();
                    qhas.erase(qhas.begin());
                }
            }

            vector<pair<int, int>> pneed;
            rep(i, 0, n) {
                if (p[i] == -1) {
                    pneed.push_back({q[i], i});
                }
            }
            sort(pneed.begin(), pneed.end());

            for (auto& [qval, i] : pneed) {
                if (*phas.begin() > qval) {
                    pos = false;
                    break;
                } else {
                    p[i] = *phas.begin();
                    phas.erase(phas.begin());
                }
            }
        }

        printYN(pos);
        if (pos) {
            rep(i, 0, n) {
                cout << p[i] << ' ';
            }
            cout << '\n';
            rep(i, 0, n) {
                cout << q[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}