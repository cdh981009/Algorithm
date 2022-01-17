#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101;

ll k[N], h[N];
int n;
pii arr[N];

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
        FOR(i, 0, n) {
            cin >> k[i];
        }
        FOR(i, 0, n) {
            cin >> h[i];
        }

        ll ans = 0;
        FOR(i, 0, n) {
            int s = k[i] - h[i] + 1;
            int e = k[i];
            arr[i] = {s, e};
        }

        sort(arr, arr + n);

        int ss = arr[0].first;
        int ee = arr[0].second;
        
        int i = 1;
        while (i < n) {
            auto &p = arr[i];
            if (p.first > ee) {
                ans += (ll)(ee - ss + 1) * (ee - ss + 2) / 2;
                ss = p.first;
                ee = p.second;
            } else {
                ee = max(ee, p.second);
            }
            i++;
        }
        ans += (ll)(ee - ss + 1) * (ee - ss + 2) / 2;

        cout << ans << '\n';
    }
    return 0;
}