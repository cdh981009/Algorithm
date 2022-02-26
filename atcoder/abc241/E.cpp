#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

ll n, k;
int a[N];
int nxt[N];
bool visited[N];
ll ans = 0;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 0, n) cin >> a[i];

    FOR(i, 0, n) {
        nxt[i] = ((ll)i + a[i]) % n;
    }

    ll len = 0;
    ll c = 0;
    ll loops = 0;
    while (true) {
        len++;
        visited[c] = true;
        loops += a[c];
        c = nxt[c];
        if (visited[c]) {
            break;
        }
    }

    ll x = 0;
    ll stl = 0;
    while (x != c) {
        len--;
        stl++;
        ans += a[x];
        loops -= a[x];
        x = nxt[x];
    }

   
    if (k > stl) {
        k -= stl;
        ll loop = k / len;
        ll rem = k % len;
        ans += loops * loop;
        while (rem--) {
            ans += a[c];
            c = nxt[c];
        }
    } else {
        ans = 0;
        int c = 0;
        while (k--) {
            ans += a[c];
            c = nxt[c];
        }
    }

    cout << ans << '\n';

    return 0;
}