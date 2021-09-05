#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;

string str;
ll ans;

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
        cin >> str;
        int a = 0;
        int b = 0;
        int n = str.size();
        FOR(i, 0, n) {
            int x = str[i] - '0';
            if (i % 2) {
                a *= 10;
                a += x;
            } else {
                b *= 10;
                b += x;
            }
        }
        cout << (ll)(a + 1) * (b + 1) - 2 << '\n';
    }
    return 0;
}