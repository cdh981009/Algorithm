#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

long long ans;

int main(int argc, char** argv) {
    int T, test_case;

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {


        int n;
        cin >> n;
        vector<int> a(n), b(n);
        FOR(i, 0, n) {
            int x;
            cin >> x;
            a[i] = x;
        }
        FOR(i, 0, n) {
            int x;
            cin >> x;
            b[i] = x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<long long> preSum(n, 0), rPreSum(n,  0), lPreSum(n, 0);
        FOR(i, 0, n) {
            preSum[i] = (i > 0 ? preSum[i - 1] : 0LL) + abs(a[i] - b[i]);
            if (i < n - 1)
                rPreSum[i] = (i > 0 ? rPreSum[i - 1] : 0LL) + abs(a[i] - b[i + 1]);
            if (i > 0)
                lPreSum[i] = (i > 1 ? lPreSum[i - 1] : 0LL) + abs(a[i] - b[i - 1]);
        }

        ans = preSum[n-1];
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                // i -> j로 보낸다
                if (i == j) continue;
                long long res = preSum[n - 1];
                if (i > j) {
                    res += (rPreSum[i - 1] - (j > 0 ? rPreSum[j - 1] : 0LL)) - (preSum[i] - (j > 0 ? preSum[j - 1] : 0LL));
                } else {
                    res += (lPreSum[j] - lPreSum[i]) - (preSum[j] - (i > 0 ? preSum[i - 1] : 0LL));
                }
                // cout << i << " " << j << " " << res << endl;
                ans = min<long long>(ans, res);
            }
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << ans << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}