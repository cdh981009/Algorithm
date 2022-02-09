#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h, vector<int>(w));
    FOR(i, 0, h) {
        FOR(j, 0, w) {
            cin >> v[i][j];
        }
    }

    FOR(j, 0, w) {
        FOR(i, 0, h) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}