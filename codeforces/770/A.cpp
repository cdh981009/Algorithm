#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
int n;

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
        int k;
        string str;
        cin >> n >> k;
        cin >> str;

        if (k >= 1) {
            bool p = true;
            FOR(i, 0, n) {
                if (str[i] != str[n - i - 1]) p = false;
            }
            ans = p ? 1 : 2;
        }
        else ans = 1;
        cout << ans << '\n';
    }
    return 0;
}