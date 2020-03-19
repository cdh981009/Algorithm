#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    bool correct = true;
    int ans = 0;
    int len = 0;
    int state = 0;
    FOR(i, 0, n) {
        char c; cin >> c;
        len++;
        state += (c == '(' ? 1 : -1);
        if (state == 0) {
            if (!correct) {
                ans += len;
            }
            len = 0;
            correct = true;
        } else if (state < 0) {
            correct = false;
        }
    }
    if (state != 0)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}