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

    int n, m; cin >> n >> m;
    vector<bool> a(21 * m + 100, false);
    vi sum(22, 0);

    FOR_(i, 1, 21) {
        int k = i;
        FOR(j, 0, m) {
            if (!a[k]) {
                sum[i]++;
                a[k] = true;
            }
            k += i;
        }
    }

    ll ans = 1;
    vector<bool> visited(n + 1, false);
    FOR_(i, 2, n) {
        if (visited[i]) continue;
        ll j = i;
        int cnt = 1;
        ans += sum[1];
        while (j * i <= n) {
            j *= i;
            cnt++;
            ans += sum[cnt];
            visited[j] = true;
        }
    }

    cout << ans << '\n';

    return 0;
}