#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    double ans;
    double a, d, k;
    cin >> a >> d >> k;

    double x = d / 100;
    double y = 0;
    double z = 1;

    int cnt = 1;

    while (true) {
        y += z * x * cnt * a;

        if (x - 1. >= DBL_EPSILON || 1. - x <= DBL_EPSILON)
            break;

        z *= (1. - x);
        x *= 1 + k / 100.0;
        x = min(1., x);

        cnt++;
    }

    ans = y;

    cout << setprecision(10) << fixed << ans << '\n';

    return 0;
}