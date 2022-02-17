#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 4e5;
constexpr int M = 12;

using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), aux(n);
    FOR(i, 0, n) cin >> a[i];

    int ans = 0;

    ll carry = 0;
    FOR(i, 0, 30) {
        int mask = (1<<(i+1))-1;
        ll cnt = 0;
        for (auto &x : a) if (x & (1<<i)) cnt++;

        int i0, i1;
        i0 = 0; i1 = n - cnt;
        for (auto &x : a)
            if (x & (1<<i)) aux[i1++] = x;
            else            aux[i0++] = x;
        swap(a, aux);

        cnt = cnt * (n - cnt);

        if ((cnt + carry) % 2) ans |= (1<<i);

        carry = 0;
        int e = n;
        FOR(j, 0, n) {
            int comp = (mask+1) - (a[j]&mask);
            while (j <= e-1) {
                if ((a[e-1]&mask) >= comp) e--;
                else break;
            }

            carry += min(n - j, n - e);
        }
    }

    cout << ans << '\n';

    return 0;
}