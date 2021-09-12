#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 101010;

int n, sn;
// 1-based array
ll seg[4 * N];

void init(const vector<ll>& arr) {
    for (sn = 1; sn < n; sn <<= 1)
        ;
    for (int i = 0; i < sn; ++i) {
        seg[i + sn] = (i < arr.size() ? arr[i] : 0);
    }
    for (int i = sn - 1; i >= 1; --i) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}

void update(int x, ll v) {
    x += n;
    seg[x] = v;
    while (x > 1) {
        x /= 2;
        seg[x] = seg[2 * x] + seg[2 * x + 1];
    }
}

ll query(int a, int b) {
    a += sn;
    b += sn;
    ll sum = 0;
    while (a <= b) {
        if (a % 2 == 1) // odd
            sum += seg[a++];
        if (b % 2 == 0) // even
            sum += seg[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    FOR(i, 0, n) {
        ll x;
        cin >> x;
        arr[i] = x;
    }

    init(arr);

    FOR(i, 0, m + k) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        } else {
            cout << query(b - 1, c - 1) << "\n";
        }
    }
    return 0;
}