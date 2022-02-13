#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define int long long

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> s(n);
    vector<int> a(n + 2, 0);
    FOR(i, 0, n) cin >> s[i];

    bool pos = true;
    int m[3] = {0, 0, 0};
    FOR(i, 0, n - 1) {
        int x;
        x = a[i + 3] = a[i] + s[i + 1] - s[i];
        m[i % 3] = min(m[i % 3], x);
    }

    FOR(i, 0, n + 2) {
        a[i] -= m[i % 3];
    }

    if (s[0] < a[0] + a[1] + a[2]) pos = false;
    else {
        int diff = s[0] - (a[0] + a[1] + a[2]);
        for (int i = 0; i < n + 2; i += 3)
            a[i] += diff;
    }

    if (!pos) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (auto &x : a)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}