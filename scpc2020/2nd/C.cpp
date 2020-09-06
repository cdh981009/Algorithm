#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n, k, q;

int main(int argc, char** argv) {
    int T, test_case;

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        cin >> n >> k >> q;

        vector<int> arr(n);
        vector<int> seg(n - k + 1);
        int sum = 0;

        FOR(i, 0, n) {
            int x;
            cin >> x;
            arr[i] = x;
            sum += x;
            if (i >= k - 1) {
                if (i >= k) {
                    sum -= arr[i - k];
                }
                seg[i - k + 1] = sum;
            }
        }

        vector<int> queryAns;
        vector<int> v(seg);
        nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        queryAns.push_back(v[v.size()/ 2]);

        FOR(i, 0, q) {
            int ind, x;
            cin >> ind >> x;
            int diff = x - arr[ind - 1];
            FOR(j, 0, k) {
                int segInd = ind - 1 - j;
                if (segInd >= 0 && segInd < n - k + 1) {
                    seg[segInd] += diff;
                }
            }
            vector<int> v(seg);
            nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
            queryAns.push_back(v[v.size() / 2]);
        }

        cout << "Case #" << test_case + 1 << endl;
        for (auto i : queryAns)
            cout << i << " ";
        cout << "\n";
    }

    return 0; //Your program should return 0 on normal termination.
}