#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
ll hc, dc, hm, dm, k, w, a;

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
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        bool pos = false;

        auto canWin = [](ll hc, ll dc, ll hm, ll dm) -> bool {
            bool pos = false;
            ll ca = (hm + dc - 1) / dc;
            ll da = (hc + dm - 1) / dm;

            //cout << ca << ' ' << da << '\n';

            if (ca <= da)
                pos = true;

            return pos;
        };

        FOR_(i, 0, k) {
            ll nhc = hc + a * i;
            ll ndc = dc + w * (k - i);
            bool res = canWin(nhc, ndc, hm, dm);
            if (res) {
                pos = true;
                break;
            }
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}