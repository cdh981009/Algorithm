// 12429: 생존자 (Small)
// https://www.acmicpc.net/problem/12429
#include <bits/stdc++.h>

using namespace std;

#define INF (1e7 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1000 + 1;
constexpr int PS = 1e5 + 1e3 + 1;

int n;
int ans;

using pii = pair<int, int>;
pii arr[N];
bool dp[PS];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    int caseNum = 1;
    while (tc--) {
        memset(dp, 0, sizeof(bool) * PS);
        ans = 0;

        cin >> n;
        FOR(i, 0, n) {
            // cin >> p >> s
            cin >> arr[i].first >> arr[i].second;
        }
        
        sort(arr, arr + n, [](const pii& l,const pii& r) {
            return l.first + l.second < r.first + r.second;
        });

        int maxT = arr[n - 1].first + arr[n - 1].second;

        // dp[n][t]: n번째 ind의 음식을 먹어야 할 차례일 때 t의 시간까지 버틸 수 있는가?
        // if (t - s[i - 1] <= p[i - 1])
        //     dp[i][t] = dp[i - 1][t] | dp[i - 1][t - s[i - 1]]
        // else
        //     dp[i][t] = dp[i - 1][t]

        dp[0] = true;

        FOR_(i, 1, n) {
            for (int t = min(i * N, maxT); t >= 0; --t) {
                int x = t - arr[i - 1].second;
                if (x >= 0 && x <= arr[i - 1].first)
                    dp[t] |= dp[x];
            }
        }

        for (int t = maxT; t >= 0; --t) {
            if (dp[t]) {
                ans = t;
                break;
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
        caseNum++;
    }

    return 0;
}