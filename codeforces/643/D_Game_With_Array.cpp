#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s; cin >> n >> s;
    if (s < 2 * n) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        FOR(i, 0, n - 1) cout << "2 ";
        cout << s - (n - 1) * 2 << "\n";
        cout << "1" << "\n";
    }
    return 0;
}