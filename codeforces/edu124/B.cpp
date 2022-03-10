#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vl a(n);
        a[0] = 1;
        bool pos = true;
        FOR(i, 1, n) {
            a[i] = a[i - 1] * 3;
            if (a[i] > 1000000000) {
                pos = false;
                break;
            }
        }

        if (!pos) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            FOR(i, 0, n) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}