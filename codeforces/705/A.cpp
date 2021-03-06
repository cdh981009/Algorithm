#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5001;

int n, k;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<int> ans;

        FOR_(i, k + 1, n) {
            ans.push_back(i);
        }

        FOR_(i, (k + 1) / 2, k - 1) {
            ans.push_back(i);
        }

        cout << ans.size() << '\n';
        if (ans.size() > 0) {
            FOR(i, 0, ans.size()) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}