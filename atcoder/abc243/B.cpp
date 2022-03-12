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
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vi a(n), b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) cin >> b[i];

    int ans1, ans2;
    ans1 = ans2 = 0;

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (a[i] == b[j]) {
                if (i == j) ans1++;
                else ans2++;
            }
        }
    }


    cout << ans1 << '\n' << ans2 << '\n';
    
    return 0;
}