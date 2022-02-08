#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e4;

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
        int n; cin >> n;
        vector<int> h(n);
        FOR(i, 0, n) cin >> h[i];

        // minimum을 target으로 하는 것이 가능한가
        auto op = [&](int target) {
            vector<int> a = h;

            for (int i = n - 1; i >= 0; --i) {
                if (a[i] < target) {
                    return false;
                }
                if (i >= 2) {
                    int d = min(h[i] / 3, (a[i] - target) / 3);
                    a[i] -= 3 * d;
                    a[i - 1] += d;
                    a[i - 2] += 2 * d;
                }
            }

            return true;
        };

        int x = 0;
        // 0에서 시작, min을 x로 맞추는게 가능할 때만 전진
        // 가능한 max에 도달
        for (int step = 1e9; step >= 1; step /= 2) {
            while (x + step <= 1e9 && op(x + step))
                x += step;
        }

        cout << x << '\n';
    }
    return 0;
}