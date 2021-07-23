#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n;
int scores[5][N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        FOR(i, 0, 5) {
            memset(scores[i], 0, sizeof(int) * n);
        }
        FOR(i, 0, n) {
            string str;
            cin >> str;
            vector<int> cnt(5, -str.size());
            FOR(j, 0, str.size()) {
                int c = str[j] - 'a';
                cnt[c] += 2;
            }
            FOR(j, 0, 5) {
                scores[j][i] = cnt[j];
            }
        }

        int ans = 0;
        FOR(i, 0, 5) {
            sort(scores[i], scores[i] + n, greater<int>());
            int j = 0;
            int sum = 0;
            while (j < n) {
                if (sum + scores[i][j] > 0) {
                    sum += scores[i][j];
                } else {
                    break;
                }
                j++;
            }
            ans = max(j, ans);
        }

        cout << ans << '\n';

    }
    return 0;
}