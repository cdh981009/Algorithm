#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main(int argc, char** argv) {
    int T, test_case;

     freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        int n;
        cin >> n;

        vector<int> ans(n + 1);
        int num = 0;
        int cnt = 0;
        int maxCnt = 1;
        int rep = 0;
        FOR_(i, 3, n) {
            ans[i] = num;
            cnt++;
            if (cnt == maxCnt) {
                cnt = 0;
                rep++;
                num++;
                if (rep == 2) {
                    maxCnt *= 2;
                    rep = 0;
                }
            }
            //cout << ans[i] << " ";
        }

        FOR(i, 0, n) {
            int x, y; cin >> x >> y;
        }


        cout << "Case #" << test_case + 1 << endl;
        cout << ans[n] << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}