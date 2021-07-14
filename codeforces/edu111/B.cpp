#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2000;

int n, a ,b;
string str;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b;
        cin >> str;
        int scr = n * (a + b);
        int prev = -1;

        int p0 = 0;
        int p1 = 0;

        FOR(i, 0, n) {
            int curr = str[i] - '0';
            if (curr != prev) {
                if (prev == 0)
                    p0++;
                if (prev == 1)
                    p1++;
            }
            prev = curr;
        }
        if (prev == 0)
            p0++;
        if (prev == 1)
            p1++;

        int cnt = 0;
        if (p0 == p1) {
            cnt = p0 + 1;
        } else {
            cnt = max(p0, p1);
        }

        scr = max(scr, n * a + cnt * b);
        // cout << cnt << endl;
        cout << scr << '\n';
    }
    return 0;
}