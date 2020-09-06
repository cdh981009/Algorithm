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

        vector<long long> preSum(n, 0), rPreSum(n, 0), lPreSum(n, 0);
        FOR(i, 0, n) {
            preSum[i] = (i > 0 ? preSum[i - 1] : 0LL) + abs(a[i] - b[i]);
            if (i < n - 1)
                rPreSum[i] = (i > 0 ? rPreSum[i - 1] : 0LL) + abs(a[i] - b[i + 1]);
            if (i > 0)
                lPreSum[i] = (i > 1 ? lPreSum[i - 1] : 0LL) + abs(a[i] - b[i - 1]);
        }

        ans = preSum[n - 1];

        vector<long long> rMinDiff(n, 0), lMinDiff(n, 0);
        FOR(i, 0, n - 1) {
            // j = [0, i] 에서
            // - rPreSum[j - 1] + preSum[j - 1] 의 min Value
            rMinDiff[i] =
                    min<long long>(
                            i > 0 ? rMinDiff[i - 1] : INF,
                            -(i > 0 ? rPreSum[i - 1] : 0LL) + (i > 0 ? preSum[i - 1] : 0LL));
            lMinDiff[i] =
                    min<long long>(
                            i > 0 ? lMinDiff[i - 1] : INF,
                            -lPreSum[i] + (i > 0 ? preSum[i - 1] : 0LL));
        }

        FOR(i, 0, n) {
            // 고정된 i에 대해 어디로 보낼지 정한다.
            // n^2 2중 루프에서 푸는 법은 다음과 같다. 이를 전처리를 통해 O(n)으로 줄인다

            // res = preSum[n - 1];
            // i -> j로 보낸다
            // i < j 일때
            // res += (lPreSum[j] - lPreSum[i]) - (preSum[j] - (i > 0 ? preSum[i - 1] : 0LL));

            // i > j 일때
            // res += (rPreSum[i - 1] - (j > 0 ? rPreSum[j - 1] : 0LL)) - (preSum[i] - (j > 0 ? preSum[j - 1] : 0LL));
            long long res;
            //res = preSum[n - 1] - abs(a[i] - b[i]);
            //ans = min<long long>(ans, res);
            if (i > 0) {
                res = preSum[n - 1] + rPreSum[i - 1] - preSum[i];
                res += rMinDiff[i - 1];
                ans = min<long long>(ans, res);

                res = preSum[n - 1] + lPreSum[i] - preSum[i];
                res += lMinDiff[i - 1];
                ans = min<long long>(ans, res);
            }
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << ans << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}