#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 9;
int cnt[N + 1];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    bool ans = true;
    int p;
    FOR(i, 0, n) {
        int x; cin >> x;

        if (++cnt[x] >= 2)
            ans = false;
        
        if (i != 0) {
            if (x == 1) {
                if ((p == 3 && cnt[2] == 0) ||
                    (p == 7 && cnt[4] == 0) ||
                    (p == 9 && cnt[5] == 0))
                    ans = false;
            }

            if (x == 3) {
                if ((p == 1 && cnt[2] == 0) ||
                    (p == 7 && cnt[5] == 0) ||
                    (p == 9 && cnt[6] == 0))
                    ans = false;
            }

            if (x == 7) {
                if ((p == 3 && cnt[5] == 0) ||
                    (p == 1 && cnt[4] == 0) ||
                    (p == 9 && cnt[8] == 0))
                    ans = false;
            }

            if (x == 9) {
                if ((p == 3 && cnt[6] == 0) ||
                    (p == 7 && cnt[8] == 0) ||
                    (p == 1 && cnt[5] == 0))
                    ans = false;
            }

            if (x == 2) {
                if (p == 8 && cnt[5] == 0) ans = false;
            }

            if (x == 8) {
                if (p == 2 && cnt[5] == 0) ans = false;
            }

            if (x == 4) {
                if (p == 6 && cnt[5] == 0) ans = false;
            }

            if (x == 6) {
                if (p == 4 && cnt[5] == 0) ans = false;
            }
        }

        p = x;
    }

    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}