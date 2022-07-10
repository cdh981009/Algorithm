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

constexpr int N = 201010;
constexpr int M = 100;

bool visited[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    
    auto op = [&](int x, int d) {
        while (x < N) {
            if (visited[x]) break;
            q.push({x, d});
            visited[x] = true;
            x *= 2;
        }
    };

    op(n, 0);

    int ans = 0;
    while (!q.empty()) {
        auto [c, d] = q.front();
        q.pop();

        if (c == k) {
            ans = d;
            break; 
        }

        op(c, d);
        if (c + 1 < N)
            op(c + 1, d + 1);
        if (c - 1 >= 0)
            op(c - 1, d + 1);
    }

    cout << ans << '\n';

    return 0;
}