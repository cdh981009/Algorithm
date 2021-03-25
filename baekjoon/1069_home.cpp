// 1069: 집으로
// https://www.acmicpc.net/problem/1069
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

    int x, y, d, t;
    cin >> x >> y >> d >> t;

    if ((double)d / t <= 1) {
        d = t = 1;
    }

    double dist = sqrt(x * x + y * y);
    double base = (int)(dist / d) * t;
    
    double rem = dist - (int)(dist / d) * d;

    // 남은거리를 걸어가는 두가지 방법
    double ans = base + rem;
    ans = min(ans, base + t + d - rem);

    // 남은거리를 지그재그 점프해 가는 방법
    if (dist >= 2 * d)
        ans = min(ans, base + t);
    else
        ans = min(ans, 2.0 * t);

    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}