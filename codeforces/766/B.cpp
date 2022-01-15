#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 5e4;

int ans;
int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m;
        if (n < m) swap(n, m);

        
        vector<int> aux;
        FOR(i, 0, n) {
            FOR(j, 0, m) {
                int res = 0;
                res = max(abs(n - 1 - i) + abs(m - 1 - j), res);
                res = max(abs(0 - i) + abs(m - 1 - j), res);
                res = max(abs(n - 1 - i) + abs(0 - j), res);
                res = max(abs(0 - i) + abs(0 - j), res);
                aux.push_back(res);
            }
        }
        sort(aux.begin(), aux.end());

        int k = n * m;
        FOR(i, 0, k) {
            cout << aux[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}