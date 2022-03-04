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

constexpr int N = 101010;
constexpr int M = 100;

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
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        sort(a.begin(), a.end());
        bool pos = false;

        int i = 0;
        int j = n - 1;
        ll sb, sr;
        sb = a[0];
        sr = a[n - 1];

        while (true) {
            if (i + 1 == j) break;
            if (n - 1 - j >= i) {
                i++;
                sb += a[i];
            } else if (sb >= sr) {
                j--;
                sr += a[j];
            }

            if (n - 1 - j < i && sr > sb) {
                pos = true;
                break;
            }
        }

        if (n - 1 - j < i && sr > sb) pos = true;


        cout << (pos ? "Yes" : "No") << '\n';
    }

    return 0;
}