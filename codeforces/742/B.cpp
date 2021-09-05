#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 301010;

int a, b;
int ans;
int memoi[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 1, N) {
        memoi[i] = memoi[i - 1] ^ i;
    }

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> a >> b;
        ans = a;
        if (memoi[a - 1] != b) {
            ans += 1 + (memoi[a] == b);
        }
        cout << ans << '\n';
    }
    return 0;
}