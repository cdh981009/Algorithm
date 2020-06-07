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
        int n; cin >> n;
        vector<int> e(n);
        FOR(i, 0, n) {
            int x; cin >> x;
            e[i] = x;
        }
        sort(e.begin(), e.end());
        int groupCnt = 0;
        int ppl = 0;
        FOR(i, 0, n) {
            ppl++;
            if (e[i] <= ppl) {
                groupCnt++;
                ppl = 0;
            }
        }
        cout << groupCnt << "\n";
    }
    return 0;
}