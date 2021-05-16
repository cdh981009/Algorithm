#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 10;
constexpr int X = (1 << 18);
constexpr int M = 1e9 + 7;

using ll = long long;

ll ans;
int n;
int sn;

int arr[N];
int seg[X];
int fac[N];
int ifac[N];

void init() {
    sn = 1;
    while (sn <= n) {
        sn <<= 1;
    }
    for (int i = 0; i < n; ++i) {
        seg[i + sn] = i;
    }
    for (int i = sn - 1; i >= 1; --i) {
        seg[i] = arr[seg[2 * i + 1]] <= arr[seg[2 * i]] ? seg[2 * i + 1] : seg[2 * i];
    }
}

int query(int a, int b) {
    a += sn;
    b += sn;
    
    int ret = 0;
    int v = INF;

    while (a <= b) {
        if (a % 2 == 1) {
            if (arr[seg[a]] < v || (arr[seg[a]] == v && seg[a] > ret)) {
                v = arr[seg[a]];
                ret = seg[a];
            }
            a++;
        }   
        if (b % 2 == 0) {
            if (arr[seg[b]] < v || (arr[seg[b]] == v && seg[b] > ret)) {
                v = arr[seg[b]];
                ret = seg[b];
            }
            b--;
        }

        a /= 2;
        b /= 2;
    }

    return ret;
}

ll getBn(int x, int y) {
    ll ret = fac[x];
    ret *= ifac[x - y];
    ret %= M;
    ret *= ifac[y];
    ret %= M;
    return ret;
}

ll solve(int l, int r, int x) {
    if (l > r)
        return 1;
    
    int piv = query(l, r);

    if (arr[piv] != x) {
        return 0;
    }

    ll left = solve(l, piv - 1, x);
    ll right = solve(piv + 1, r, x + 1);
    ll binom = getBn(r - l, piv - l);

    ll ret = (left * right) % M;
    ret = (ret * binom) % M;

    return ret;
}

int modPow(int a, int b, int m) {
    if (b == 0)
        return 1;
    long long h = modPow(a, b / 2, m);
    h = (h * h) % m;
    if (b % 2 == 1)
        h = (h * a) % m;
    return h;
}

void pre() {
    ll p = 1;
    FOR(i, 1, N) {
        p *= i;
        p %= M;
        fac[i] = p;
        ifac[i] = modPow(p, M - 2, M);
    }
    fac[0] = 1;
    ifac[0] = ifac[1];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pre();

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }

        init();

        ans = solve(0, n - 1, 1);

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}