#include <algorithm>
#include <iostream>
#include <set>
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
        ans = 0LL;
        int n;
        long long m;
        cin >> n >> m;

        set<long long> preSum;
        long long sum = 0LL;
        FOR(i, 0, n) {
            preSum.insert(sum);

            long long x;
            cin >> x;
            sum += x;
            
            long long value = sum - m;
            auto res = preSum.lower_bound(value);
            if (res != preSum.end())
                ans = max<long long>(ans, sum - *res);
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << ans << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}