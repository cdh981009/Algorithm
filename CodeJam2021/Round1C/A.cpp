#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30;
constexpr int M = 50;

double ans;
int n, k;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> n >> k;

        FOR(i, 0, n) {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        int u = unique(arr, arr + n) - arr;

        vector<int> p1;
        int maxV = 0;

        int l = arr[0] - 1;
        if (l != 0)
            p1.push_back(l);
        l = k - arr[u - 1];
        if (l != 0)
            p1.push_back(l);
        FOR(i, 0, u - 1) {
            if (arr[i + 1] == arr[i] + 1)
                continue;

            l = (arr[i + 1] - arr[i]) / 2;
            p1.push_back(l);
            l = (arr[i + 1] - arr[i] - 1);
            maxV = max(maxV, l);
        }

        sort(p1.rbegin(), p1.rend());
        int x = 0;
        if (p1.size() != 0) {
            x += p1[0];
            if (p1.size() != 1) {
                x += p1[1];
            }
        }

        x = max(x, maxV);

        ans = (double)x / k;

        cout << setprecision(9) << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}