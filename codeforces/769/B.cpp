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
        cin >> n;
        int x;
        for (int i = 30; i >= 0; --i) {
            x = (1 << i);
            if ((n - 1) & x) break;
        }
        for (int i = n - 1; i > x; --i) {
            cout << i << ' ';
        }
        cout << x << ' ' << 0 << ' ';
        for (int i = x - 1; i > 0; --i) {
            cout << i << ' ';
        }
        cout << '\n';
        
    }
    return 0;
}