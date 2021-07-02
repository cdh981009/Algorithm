#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

const int N = 201010;
ll arr[N];
ll dist[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, x; cin >> n >> k >> x;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int gCnt = 0;
    
    FOR(i, 0, n - 1) {
        if (arr[i + 1] - arr[i] > x) {
            dist[gCnt] = arr[i + 1] - arr[i];
            gCnt += 1;
        }
    }

    sort(dist, dist + gCnt);

    ll ans = gCnt + 1;

    FOR(i, 0, gCnt) {
        ll v = (dist[i] - 1) / x;
        if (k >= v) {
            k -= v;
            ans -= 1; 
        } else {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}