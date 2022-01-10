#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 25e4;
constexpr int W = 125e4;
int n, w;
ll ans = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> w;
    vector<ll> a3, a5;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        if (x == 3)
            a3.push_back(y);
        else
            a5.push_back(y);
    }

    sort(a3.rbegin(), a3.rend());
    sort(a5.rbegin(), a5.rend());

    FOR(i, 1, a3.size())
        a3[i] += a3[i - 1];

    FOR(i, 1, a5.size())
        a5[i] += a5[i - 1];

    FOR(i, 0, a3.size() + 1) {
        int ww = w - i * 3;
        if (ww < 0)
            break;
        ww /= 5;
        ww -= 1;
        ww = min(ww, (int)a5.size() - 1);

        ans = max(ans, (ll)(i >= 1 ? a3[i - 1] : 0) + (ww >= 0 ? a5[ww] : 0));
    }

    cout << ans << '\n';

    return 0;
}