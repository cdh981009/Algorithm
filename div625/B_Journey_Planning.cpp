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

    int len; cin >> len;
    map<int, long long> sum; 
    FOR(i, 0, len) {
        int b; cin >> b;
        sum[b - i] += b;
    }
    long long ans = 0;
    for (auto p : sum)
        ans = max(ans, p.second);
    cout << ans << endl;
    return 0;
}