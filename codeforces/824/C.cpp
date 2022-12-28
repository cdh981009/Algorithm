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

constexpr int N = 300;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];
vector<int> to, from, vst;

int dfs(int curr) {
    if (vst[curr]) return 0;
    vst[curr] = 1;

    if (to[curr] == -1) return 26;
    else return dfs(to[curr]) + 1;
}


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
        to = vector<int>(26, -1);
        from = vector<int>(26, -1);

        string t, s;
        cin >> n >> t;

        rep(i, 0, n) {
            int c = t[i] - 'a';

            if (to[c] == -1) {
                rep(i, 0, 27) {
                    if (c == i) continue;
                    if (from[i] == -1) {
                        to[c] = i;
                        from[i] = c;

                        vst = vector<int>(26, 0);
                        if (dfs(i) < 26) {
                            from[i] = -1;
                        } else {
                            break;
                        }
                    }
                }
            }
            
            s.push_back(to[c] + 'a');
        }

        cout << s << '\n';
    }

    return 0;
}