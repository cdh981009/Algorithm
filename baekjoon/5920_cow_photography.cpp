// 5920: Cow Photography
// https://www.acmicpc.net/problem/5920
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e4 + 1;
int arr[5][N];
int ans[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, 5) {
        FOR(pos, 0, n) {
            int x;
            cin >> x;
            arr[i][x] = pos;
            if (i == 0) {
                ans[pos] = x;
            }
        }
    }

    auto f = [](int x, int y) {
        int parity = 0;
        FOR(i, 0, 5) {
            parity += arr[i][x] < arr[i][y];
        }

        return parity >= 3;
    };

    FOR(i, 0, n - 1) {
        if (!f(ans[i], ans[i + 1])) // x > y;
            swap(ans[i], ans[i + 1]);
    }

    for (int i = n - 1; i >= 1; --i) {
        if (f(ans[i], ans[i - 1])) // x < y
            swap(ans[i], ans[i - 1]);
    }

    FOR(i, 0, n) {
        cout << ans[i] << "\n";
    }

    return 0;
}