#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 201010;

int n;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        long long cnt = 2LL * n - 1;

        if (n >= 3) {
            int v0 = arr[0];
            int v1 = arr[1];
            int v2, v3;
            FOR(i, 0, n - 2) {
                v2 = arr[i + 2];
                int mn = min(v0, min(v1, v2));
                int mx = max(v0, max(v1, v2));
                if ((mn == v1 && mn != v0 && mn != v2) || (mx == v1 && mx != v0 && mx != v2)) {
                    cnt++;
                }

                if (i + 3 != n) {
                    v3 = arr[i + 3];
                    int mn = min(min(v0, v1), min(v2, v3));
                    int mx = max(max(v0, v1), max(v2, v3));
                    if ((mn != v0 && mx != v3) && (mn != v3 && mx != v0)) {
                        cnt++;
                    }
                }
                v0 = v1;
                v1 = v2;
            }
        }

        cout << cnt << '\n';

    }
    return 0;
}