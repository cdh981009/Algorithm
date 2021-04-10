#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e2;
constexpr int M = 50;

int n;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        int ans = 0;
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }
        // brute force
        FOR(i, 0, n - 1) {
            int minVal = INF;
            int minInd = -1;
            FOR(j, i, n) {
                if (arr[j] < minVal) {
                    minVal = arr[j];
                    minInd = j;
                }
            }
            // cost
            ans += minInd - i + 1;
            // reverse
            int j = 0;
            while (i + j < minInd - j) {
                swap(arr[i + j], arr[minInd - j]);
                j++;
            }
        }
        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}