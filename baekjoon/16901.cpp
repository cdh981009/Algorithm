#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 201010;
constexpr int L = 29;

int n;
vector<int> a;
ll ans = 0;

void minxor(int ss, int se, int ds, int de) {
    int ret = INF;
    FOR_(i, ss, se) {
        int x = a[i];
        int s = ds;
        int e = de;
        int k = 0;
        for (int j = L; j >= 0; --j) {
            int bit = (x & (1 << j));
            int it = lower_bound(a.begin() + s, a.begin() + e + 1, k | (1 << j)) - a.begin();
            if (!bit) {
                if (it != s) {
                    e = it - 1;
                } else { // only 1
                    k |= (1 << j);
                }
            } else {
                if (it != e + 1) {
                    s = it;
                    k |= (1 << j);
                }
            }
        }

        ret = min(ret, x ^ a[s]);
    }

    ans += ret;
}

void solve(int s, int e) {
    if (a[s] != a[e]) {
        int i = L;
        int x = 0;
        while (true) {
            if (a[e] & (1 << i)) {
                x |= (1 << i);
                if (!(a[s] & (1 << i))) break;
            }
            i--;
        }

        int piv = lower_bound(a.begin() + s, a.begin() + e + 1, x) - a.begin();

        solve(s, piv - 1); solve(piv, e);

        if (piv - 1 - s > e - piv) {
            minxor(piv, e, s, piv - 1);
        } else {
            minxor(s, piv - 1, piv, e);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    FOR(i, 0, n)
        cin >> a[i];
    sort(a.begin(), a.end());

    solve(0, n - 1);

    cout << ans << '\n';
    return 0;
}