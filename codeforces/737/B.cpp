#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n, k;
pair<int, int> arr[N];

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
        cin >> n >> k;
        FOR(i, 0, n) {
            int x; cin >> x;
            arr[i] = {x, i};
        }
        bool pos = false;

        sort(arr, arr + n);
        
        int cnt = 1;
        int prev = arr[0].second;

        FOR(i, 1, n) {
            int curr = arr[i].second;
            if (prev + 1 != curr) {
                cnt++;
            }
            prev = curr;
        }

        if (cnt <= k)
            pos = true;

        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}