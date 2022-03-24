#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, ans, k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vll a(n);
        bool noOne = true;
        FOR(i, 0, n) {
            cin >> a[i];
            if (a[i] == 1) noOne = false;
        }

        bool pos = false;

        if (noOne) {
            pos = true;
        } else { // there is at least one 1
            sort(a.begin(), a.end());
            if (a.front() == 0) {
                pos = false;
            } else {
                pos = true;
                FOR(i, 1, n) {
                    if (a[i - 1] + 1 == a[i]) {
                        pos = false;
                        break;
                    }
                }
            }
        }



        cout << (pos ? "YES" : "NO") << '\n';
    }

    return 0;
}