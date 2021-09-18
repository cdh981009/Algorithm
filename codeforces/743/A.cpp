#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n;
vector<int> require[N];
int dp[N];
int memoi[N];
int ans;

int getDp(int node) {
    if (memoi[node] == 2)
        return dp[node];
    
    memoi[node] = 1;

    int& ret = dp[node];
    ret = 1;
    
    FOR(i, 0, require[node].size()) {
        int nxt = require[node][i];
        if (memoi[nxt] == 1)
            return ret = INF;
        ret = max(ret, getDp(nxt) + (nxt < node ? 0 : 1));
    }

    memoi[node] = 2;

    return ret;
}

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
        cin >> n;
        memset(require, 0, sizeof(vector<int>) * n);
        memset(memoi, 0, sizeof(int) * n);
        FOR(i, 0, n) {
            int k; cin >> k;
            FOR(j, 0, k) {
                int a; cin >> a; a--;
                require[i].push_back(a);
            }
        }
        ans = 0;

        FOR(i, 0, n) {
            ans = max(ans, getDp(i));
        }

        if (ans >= INF)
            ans = -1;
        
        cout << ans << '\n';

    }
    return 0;
}