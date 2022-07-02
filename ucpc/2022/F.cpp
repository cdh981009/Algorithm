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

int n, m, s;

vector<char> v;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    string str;
    map<char, vpii> chars;
    map<char, int> req;
    rep(i, 0, n) {
        cin >> str;
        rep(j, 0, m) {
            chars[str[j]].push_back({i, j});
        }
    }
    cin >> str;
    rep(i, 0, s) {
        req[str[i]]++;
    }

    ll ans = 0;
    string route;

    int x, y;
    x = y = 0;
    while (true) {
        bool pos = true;

        for (auto [c, x] : req) {
            if (chars[c].size() < x) {
                pos = false;
                break;
            }
        }

        auto op = [&](int nx, int ny, bool pick = true) {
            while (x < nx) {
                route.push_back('D');
                x++;
            }
            while (x > nx) {
                route.push_back('U');
                x--;
            }
            while (y < ny) {
                route.push_back('R');
                y++;
            }
            while (y > ny) {
                route.push_back('L');
                y--;
            }
            if (pick)
                route.push_back('P');
        };

        if (pos) {
            rep(i, 0, s) {
                char go = str[i];
                auto [nx, ny] = chars[go].back();
                op(nx, ny);
                chars[go].pop_back();
            }
            ans++;
        } else {
            // route to exit
            op(n-1, m-1, false);
            break;
        }
    }

    cout << ans << ' ' << route.size() << '\n';
    cout << route << '\n';

    return 0;
}