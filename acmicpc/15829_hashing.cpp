#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string str; cin >> str;
    int M = 1234567891;
    int r = 31;
    long long ri = 1;
    long long ans = 0;
    FOR(i, 0, n) {
        int x = str[i] - 'a' + 1;
        ans += x * ri;
        ans %= M;
        ri *= r;
        ri %= M;
    }
    cout << ans << "\n";
    return 0;
}