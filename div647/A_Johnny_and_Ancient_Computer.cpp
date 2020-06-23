#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        long long a, b; cin >> a >> b;
        if (a < b) swap (a, b);
        int cnt = 0;
        bool matches = false;
        while (true) {
            if (a == b) matches = true;
            if (a <= b) break;
            cnt++;
            b <<= 1;
        }
        int ans = 0;
        ans += cnt / 3;
        cnt %= 3;
        ans += cnt / 2;
        cnt %= 2;
        ans += cnt;
        cout << (matches ? ans : -1) << "\n";
    }
    return 0;
}