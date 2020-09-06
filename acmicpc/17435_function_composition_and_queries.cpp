#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e5;
constexpr int M = 2e5;
constexpr int logN = 20; 
int fx[M + 1][logN];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m;
    FOR(i, 0, m) {
        int x; cin >> x;
        fx[i + 1][0] = x;
    }
    FOR(i, 1, logN) {
        FOR(j, 0, M + 1) {
            int x = fx[j][i - 1];
            fx[j][i] = fx[x][i - 1];
        }
    }
    int q; cin >> q;
    FOR(i, 0, q) {
        int n, x; cin >> n >> x;
        int ans = x;
        while (n > 0) {
            int cnt = 0;
            int num = 1;
            while (num * 2 <= n) {
                num *= 2;
                cnt++;
            }
            ans = fx[ans][cnt];
            n -= num;
        }
        cout << ans << "\n";
    }
    return 0;
}