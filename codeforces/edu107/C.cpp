#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e5;
constexpr int M = 55;

int n, q;
int ind[M];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    FOR(i, 0, M) {
        ind[i] = N + 10;
    }

    FOR(i, 0, n) {
        int x;
        cin >> x;
        ind[x] = min(ind[x], i + 1);
    }

    FOR(i, 0, q) {
        int x; cin >> x;
        int ans = ind[x];
        cout << ans << ' ';
        FOR(i, 0, M) {
            if (ind[i] < ans) {
                ind[i]++;
            }
        }
        ind[x] = 1;
    }
    cout << '\n';
    return 0;
}