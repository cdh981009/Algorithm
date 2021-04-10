#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e2;
constexpr int M = 50;

int n, c;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        bool possible = true;
        cin >> n >> c;
        
        if (c < n - 1 || c > (n * (n + 1)) / 2 - 1)
            possible = false;
        
        if (possible) {
            // init
            FOR(i, 0, n) {
                arr[i] = i + 1;
            }

            FOR(i, 0, n - 1) {
                int maxCost = i + 2;
                int find = n - 1 - i;
                int remainingStep = find - 1;
                int targetCost = min(c - remainingStep, maxCost);
                c -= targetCost;

                // reverse from [find - 1] to [find - 1 + targetCost - 1];
                int j = 0;
                while (find - 1 + j < find - 2 + targetCost - j) {
                    swap(arr[find - 1 + j], arr[find - 2 + targetCost - j]);
                    j++;
                }
            }
        }

        cout << "Case #" << caseNum << ": ";
        if (possible) {
            FOR(i, 0, n)
                cout << arr[i] << ' ';
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << '\n';
    }

    return 0;
}