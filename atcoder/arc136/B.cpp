#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 998244353;

int n;
vector<int> a, b;

// operation invariant: counting inversion!!

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a = vector<int>(n);
    b = vector<int>(n);

    vector<int> cnta(5010, 0);
    vector<int> ind(5010, 0);
    vector<int> cntb(5010, 0);

    bool u = true;
    FOR(i, 0, n) {
        cin >> a[i];
        cnta[a[i]]++;
        if (cnta[a[i]] >= 2) u = false;
    }

    FOR(i, 0, n) {
        cin >> b[i];
        cntb[b[i]]++;
    }

    bool pos = true;
    FOR(i, 0, 5010) {
        if (cnta[i] != cntb[i]) {
            pos = false;
            break;
        }
    }

    if (pos) {
        if (u) {
            // counting inversion
            int ainv, binv;
            ainv = binv = 0;
            FOR(i, 0, n) {
                FOR(j, i + 1, n) {
                    if (a[i] > a[j]) {
                        ainv++;
                    }
                    if (b[i] > b[j]) {
                        binv++;
                    }
                }
            }

            if (ainv % 2 != binv % 2) pos = false;
        }
    }

    cout << (pos ? "Yes" : "No") << '\n';

    return 0;
}