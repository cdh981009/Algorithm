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

constexpr int N = 110;
constexpr int M = 8e6 + 10;
constexpr int B = 4e6;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    s--;
    vector<ll> pos(n), fuel(n), ans;
    rep(i, 0, n) cin >> pos[i];
    rep(i, 0, n) cin >> fuel[i];

    queue<int> q;
    int l, r;
    l = r = s;
    l--, r++;
    ll mn, mx;
    mn = mx = pos[s];
    q.push(s);
    while (!q.empty()) {
        auto curr = q.front();
        ans.push_back(curr);
        q.pop();
        mn = min(mn, pos[curr] - fuel[curr]);
        mx = max(mx, pos[curr] + fuel[curr]);
        while (l >= 0) {
            if (pos[l] >= mn) q.push(l), l--;
            else break;
        }
        while (r < n) {
            if (pos[r] <= mx) q.push(r), r++;
            else break;
        }
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x + 1 << ' ';
    cout << '\n';
    return 0;
}