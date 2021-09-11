#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int(i) = (a); (i) <= (b); ++(i))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr int N = 501010;
constexpr int M = 201010;

int n;
int p[N];
int c[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    p[1] = 1;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (p[i] == i) {
            p[i] = i;
            for (int j = i * i; j <= n; j += i) {
                p[j] = i;
            }
        }
    }
    FOR_(i, 1, n) {
        if (p[i] == i)
            c[i] = ++cnt;
    }
    cout << cnt << '\n';
    FOR_(i, 1, n) {
        cout << c[p[i]] << ' ';
    }
    cout << '\n';

    return 0;
}