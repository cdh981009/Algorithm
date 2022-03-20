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

    int x, y;
    x = y = 0;
    int n; cin >> n;
    string t; cin >> t;

    int dir = 0;
    FOR(i, 0, n) {
        if (t[i] == 'R') {
            dir += 1;
            dir %= 4;
        } else {
            x += "2101"[dir] - '1';
            y += "1012"[dir] - '1';
        }
    }

    cout << x << ' ' << y << '\n';

    return 0;
}