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

    int n; cin >> n;
    int m = (1 << n);
    vector<vector<int>> winVersus(m + 1, vector<int>());
    vector<int> lostVersus(m + 1, 0);
    vector<int> winCnt(m + 1, 0);
    vector<int> cnt(n + 1, 0);

    rep(i, 0, m-2) {
        int a, b;
        cin >> a >> b;
        winCnt[a]++;
        winVersus[a].push_back(b);
        lostVersus[b] = a;
    }

    vector<int> cand;
    vector<pair<int, int>> ans;

    rep_(i, 1, m) {
        if (lostVersus[i] == 0 && winCnt[i] != n)
            cand.push_back(i);
        cnt[winCnt[i]]++;
    }

    int k;
    rep(i, 0, n) {
        int expect = (1 << (n - 1 - i));
        if (cnt[i] == expect + 1) {
            k = i;
            break;
        }
    }

    vector<vector<int>> sets(m + 1, vector<int>(n + 1, 0));
    
    rep_(i, 1, m) {
        for (auto& w : winVersus[i])
            sets[i][winCnt[w]]++;
    }

    auto valid = [&](int x) {
        bool first = false;
        for (int i = n; i>= 0; --i) {
            auto& y = sets[x][i];
            if (y < 0 || y > 1) return false;
            if (y == 1) first = true;
            else if (first) return false;
        }
        return true;
    };

    for (auto &y : cand) {
        rep_(x, 1, m) {
            if (winCnt[x] != k || x == y) continue;
            bool pos = true;
            sets[x][winCnt[y]]++;
            pos &= valid(x);
            sets[x][winCnt[y]]--;
            
            int z = lostVersus[x];
            if (z != 0) {
                sets[z][winCnt[x]]--;
                sets[z][winCnt[x] + 1]++;
                pos &= valid(z);
                sets[z][winCnt[x]]++;
                sets[z][winCnt[x] + 1]--;
            }

            if (pos)
                ans.push_back({x, y});
            if (ans.size() == 2) break;
        }
        if (ans.size() == 2) break;
    }

    sort(ans.begin(), ans.end());
    for (auto &[x, y] : ans)
        cout << x << ' ' << y << '\n';

    return 0;
}