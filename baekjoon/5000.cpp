#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 100;
constexpr int M = 998244353;

int n;
vector<int> a, b;

// operation invariant: counting inversion!!


ll _m(int s, int e, vi& arr, vi& aux) {
    int m = (s + e) / 2;

    int i = s;
    int j = m;
    int k = s;
    ll sum = 0;

    while (i < m && j < e) {
        if (arr[i] > arr[j]) {
            sum += m - i;
            aux[k++] = arr[j++];
        } else {
            aux[k++] = arr[i++];
        }
    }

    while (i < m) {
        aux[k++] = arr[i++];
    }

    while (j < e) {
        aux[k++] = arr[j++];
    }

    FOR(i, s, e) {
        arr[i] = aux[i];
    }

    return sum;
}

ll merge(int s, int e, vi& arr, vi& aux) {
    if (e - s == 1) return 0;

    int m = (s + e) / 2;

    ll l = merge(s, m, arr, aux);
    ll r = merge(m, e, arr, aux);

    return l + r + _m(s, e, arr, aux);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a = vi(n);
    b = vi(n);

    FOR(i, 0, n) {
        cin >> a[i];
    }

    FOR(i, 0, n) {
        cin >> b[i];
    }

    bool pos = true;

    // counting inversion
    vi aux(n);
    ll ainv = merge(0, n, a, aux);
    ll binv = merge(0, n, b, aux);

    if (ainv % 2 != binv % 2) pos = false;

    cout << (pos ? "Possible" : "Impossible") << '\n';

    return 0;
}