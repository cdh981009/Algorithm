#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1010;

int n;
int arr[N];
ll ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    FOR(i, 0, n) {
        if (i % 2)
            continue;
        ll start = arr[i];
        ll curr = 0;
        ll prev = 0;
        FOR(j, i + 1, n) {
            if (j % 2)
                curr -= arr[j];
            else
                curr += arr[j];

            if (prev > 0 && curr <= 0)
                ans++;

            if (curr < 0) {
                ll x = min(start, -curr);
                ans += x;
                start -= x;
                curr += x;

            }

            if (-curr > start) {
                break;
            }

            prev = curr;
        }
    }

    cout << ans << '\n';

    return 0;
}