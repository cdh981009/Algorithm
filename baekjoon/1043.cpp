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

constexpr int N = 100;
constexpr int M = 100;

int n, m, x;
vi truth;
vector<vi> ind2parties(N);
vector<vi> parties(N);
bool pvisited[N];
bool tvisited[N];


void dfs(int t) {
    if (tvisited[t]) return;
    tvisited[t] = true;
    for (auto &p : ind2parties[t]) {
        if (pvisited[p]) continue;
        pvisited[p] = true;
        for (auto &nt : parties[p]) {
            dfs(nt);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> x;
    rep(i, 0, x) {
        ll t; cin >> t;
        truth.push_back(t);
    }

    rep(i, 0, m) {
        ll k;
        cin >> k;
        rep(j, 0, k) {
            ll t; cin >> t;
            parties[i].push_back(t);
            ind2parties[t].push_back(i);
        }
    }

    rep(i, 0, x) {
        dfs(truth[i]);
    }

    int cnt = 0;
    rep(i, 0, m) {
        if (!pvisited[i]) cnt++;
    }
    cout << cnt << '\n';


    return 0;
}