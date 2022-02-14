#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

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
        int n, ans;
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) cin >> a[i];
        
        int t = 1;
        int s = -1;
        FOR(i, 0, n) {
            if (s == -1) {
                if (a[i] == i + 1) {
                    t++;
                } else {
                    s = i;
                }
            }
            else {
                if (a[i] == t) {
                    //cout << t << ' ' << i << '\n';
                    reverse(a.begin() + s, a.begin() + i + 1);
                    break;
                }
            }
        }

        for (auto &x : a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}