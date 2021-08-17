#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5010;
constexpr int M = 1e9 + 7;

using ll = long long;

int n;
int arr[N];
ll pre[N];
ll ans[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    int mx = 0;
    int mxi = -1;
    FOR(i, 0, n) {
        if (arr[i] > mx) {
            mx = arr[i];
            mxi = i;
            ans[i] = (i == 0 ? 0 : pre[i - 1]) + 1;
            ans[i] %= M;
        } else {
            ans[i] = ans[mxi];
        }
        pre[i] = (i == 0 ? 0 : pre[i - 1]) + ans[i];
        pre[i] %= M;
    }

    cout << ans[n - 1] << '\n';

    return 0;
}