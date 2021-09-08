#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2000;

using ll = long long;
using pii = pair<int, int>;

int n;
string str;

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
        cin >> str;
        int l, r;
        l = r = -1;
        FOR(i, 0, n - 1) {
            if (str[i] != str[i + 1]) {
                l = i + 1;
                r = i + 2;
                break;
            }
        }

        cout << l << ' ' << r << '\n';
    }
    return 0;
}