#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 201010;
constexpr double E = 0.0000000001;
double ans = 0;

void solve(double c, double m, double p, double v, double x, int cnt) {
    ans += x * p * cnt;

    double nc, nm, np;
    
    if (c >= E) {
        if (c <= v) {
            nc = -1.;
            if (m >= E) {
                nm = m + c / 2.;
                np = p + c / 2.;
            } else {
                nm = m;
                np = p + c;
            }
        } else {
            nc = c - v;
            if (m >= E) {
                nm = m + v / 2.;
                np = p + v / 2.;
            } else {
                nm = m;
                np = p + v;
            }
        }
        solve(nc, nm, np, v, x * c, cnt + 1);
    }

    if (m >= E) {
        if (m <= v) {
            nm = -1.;
            if (c >= E) {
                nc = c + m / 2.;
                np = p + m / 2.;
            } else {
                nc = c;
                np = p + m;
            }
        } else {
            nm = m - v;
            if (c >= E) {
                nc = c + v / 2.;
                np = p + v / 2.;
            } else {
                nc = c;
                np = p + v;
            }
        }
        solve(nc, nm, np, v, x * m, cnt + 1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        ans = 0.;
        double c, m, p, v;
        cin >> c >> m >> p >> v;
        solve(c, m, p, v, 1, 1);
        cout << setprecision(20) << ans << '\n';
    }
    return 0;
}