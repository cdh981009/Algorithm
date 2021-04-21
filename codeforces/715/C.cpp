#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2000;

int n;
using pii = pair<int, int>;
using ll = long long;
pii arr[N];
map<int, int> m;

ll dp[N][N];

ll getDp(int l, int r) {
    if (l == r) {
        return 0;
    }

    ll& ref = dp[l][r];
    if (ref != -1)
        return ref;

    ll ln = arr[l].first;
    ll lc = arr[l].second;
    ll rn = arr[r].first;
    ll rc = arr[r].second;
    ll diff = rn - ln;

    if (l + 1 == r) {
        ref = min(lc, rc) * diff;
    } else {
        ref = getDp(l + 1, r) + lc * diff;
        ref = min(ref, getDp(l, r - 1) + rc * diff);
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(ll) * N * N);

    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        m[x]++;
    }
    int un = m.size();
    int i = 0;
    for (auto& p : m) {
        arr[i++] = p;
    }

    cout << getDp(0, un - 1) << '\n';

    return 0;
}