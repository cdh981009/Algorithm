#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e5;
constexpr int M = 998244353;

int n, m;
using ll = long long;

int arr[N];
int dpRow[N];
int dpCol[N];
pair<ll, ll> p[N];

int modPow(int a, int b, int m) {
    if (b == 0)
        return 1;
    long long h = modPow(a, b / 2, m);
    h = (h * h) % m;
    if (b % 2 == 1)
        h = (h * a) % m;
    return h;
}

// m is a prime
int inv(int x, int m = M) {
    return modPow(x, m - 2, m);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int cnt = 0;
    FOR(i, 0, n * m) {
        char x; cin >> x;
        if (x == 'o') {
            arr[i] = true;
            cnt++;
        }
    }

    ll sq2 = inv(2);
    p[0] = {1, (sq2 * sq2) % M};
    FOR(i, 1, N) {
        p[i].first = (p[i - 1].first * 2 + (i % 2 == 1 ? -1 : +1)) % M;
        p[i].second = (p[i - 1].second * sq2) % M;
    }

    FOR(x, 0, m) {
        FOR(y, 0, n) {
            if (x > 0 && arr[y * m + x - 1])
                dpRow[y * m + x] = dpRow[y * m + x - 1] + 1;
            if (y > 0 && arr[(y - 1) * m + x])
                dpCol[y * m + x] = dpCol[(y - 1) * m + x] + 1;
        }
    }

    ll base = modPow(2, cnt, M);
    ll ans = 0;

    FOR(x, 0, m) {
        FOR(y, 0, n - 1) {
            if (arr[y * m + x] && arr[(y + 1) * m + x]) {
                auto& i = p[dpCol[y * m + x]];
                ll res = i.first * i.second;
                res %= M;
                res *= base;
                res %= M;

                ans += res;
                ans %= M;
            }
        }
    }

    FOR(y, 0, n) {
        FOR(x, 0, m - 1) {
            if (arr[y * m + x] && arr[y * m + x + 1]) {
                auto& i = p[dpRow[y * m + x]];
                ll res = i.first * i.second;
                res %= M;
                res *= base;
                res %= M;

                ans += res;
                ans %= M;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}