#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 11;
constexpr int M = 2e6 + 10;
constexpr int L = 1e6;
int arr[N];
int aux[N];
int n, k;
// dp[i][j][x] i 번째 원소까지 확인 했을 때
// j번째 원소를 제외한 나머지를 조합해 x를 만들 수 있나
map<int, bool> dp[N][N];

bool getDp(int i, int j, int x) {
    if (i == 0)
        return x == 0;

    if (dp[i][j].count(x) == 1)
        return dp[i][j][x];
    else {
        bool m;
        if (i - 1 == j) {
            m = getDp(i - 1, j, x);
        } else {
            m = getDp(i - 1, j, x) || getDp(i - 1, j, x - arr[i - 1]) || getDp(i - 1, j, x + arr[i - 1]);
        }
        return dp[i][j][x] = m;
    }

   
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
            arr[i] = abs(arr[i]);
            aux[i] = arr[i];
        }
        sort(aux, aux + n);
        int cnt = unique(aux, aux + n) - aux;

        bool pos;
        if (cnt != n || aux[0] == 0) {
            pos = true;
        } else {
            pos = false;
            FOR(i, 0, N) {
                FOR(j, 0, N) {
                    dp[i][j].clear();
                }
            }
            FOR(i, 0, n) {
                if (getDp(n, i, arr[i])) {
                    pos = true;
                    break;
                }
            }
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}