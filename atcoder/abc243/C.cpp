#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n;
    map<int, vpii> poss;
    FOR(i, 0, n) {
        int _x, _y; cin >> _x >> _y;
        poss[_y].push_back({_x, i});
    }
    cin >> s;

    bool pos = false;
    for (auto &[y, v] : poss) {
        sort(v.begin(), v.end());
        bool r = false;
        for (auto &[x, i] : v) {
            if (s[i] == 'L' && r) {
                pos = true;
                break;
            }

            if (s[i] == 'R') {
                r = true;
            }
        }

        if (pos) break;
    }

    cout << (pos ? "Yes" : "No") << '\n';

    return 0;
}