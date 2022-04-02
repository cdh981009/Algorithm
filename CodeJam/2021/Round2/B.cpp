#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6 + 10;
constexpr int M = 50;

int ans;
int n;
int dp[N];
bool mem[N];

int getDp(int x) {
    if (x == 0)
        return 0;
    if (x == 1)
        return -INF;

    int& ref = dp[x];
    bool& m = mem[x];

    if (m)
        return ref;
    m = true;

    ref = 1;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int p = i;
            int q = x / i;

            if (q >= 2) {
                ref = max(ref, 1 + getDp(p - 1));
            }
            ref = max(ref, 1 + getDp(q - 1));
        }
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> n;
        ans = 1;

        for (int i = 3; i * i <= n; ++i) {
            if (n % i == 0) {
                int p = i;
                int q = n / i;

                if (q != 2) {
                    ans = max(ans, 1 + getDp(p - 1));
                }
                ans = max(ans, 1 + getDp(q - 1));
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}