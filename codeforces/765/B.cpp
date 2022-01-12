#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 15e4 + 10;

int ans;
int arr[N];
vector<int> ind[N];
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
        FOR(i, 0, N) {
            ind[i].clear();
        }
        
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
            ind[arr[i]].push_back(i);
        }

        int ans = -1;
        FOR(i, 0, N) {
            if (ind[i].size() >= 2) {
                FOR(j, 1, ind[i].size()) {
                    ans = max(ans, n - ind[i][j] + ind[i][j - 1]);
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}