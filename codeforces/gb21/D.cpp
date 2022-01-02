#include <bits/stdc++.h>

using namespace std;

#define INF 6e4
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e4 + 20;

using ll = long long;

int n, x;
int arr[N];
int ans = 0;
int dp[N][3];

int getDp(int ind, int p) {
    if (ind == n)
        return 0;

    int &ref = dp[ind][p];

    if (ref != -1)
        return ref;
    
    ref = 0;

    ref = max(ref, getDp(ind + 1, 0));
    if (p == 0) {
        ref = max(ref, 1 + getDp(ind + 1, 1));
    } else if (p == 1) {
        int x = arr[ind - 1] + arr[ind];
        // pickable
        if (x >= 0) {
            ref = max(ref, 1 + getDp(ind + 1, 2));
        }
    } else { // p == 2
        int x = arr[ind - 1] + arr[ind - 2] + arr[ind];
        int y = arr[ind - 1] + arr[ind];
        if (x >= 0 && y >= 0)
            ref = max(ref, 1 + getDp(ind + 1, 2));
    }

    return ref;
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
        ans = 0;
        memset(dp, -1, sizeof(dp));

        cin >> n;

        FOR(i, 0, n) {
            cin >> arr[i];
        }
        cin >> x;

        FOR(i, 0, n) {
            arr[i] -= x;
        }

        cout << getDp(0, 0) << '\n';
    }

    return 0;
}