#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 11;
constexpr int M = 1e6 + 10;
int arr[N];
int aux[N];
bool cnt[M];
int n, k;

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
        int u = unique(aux, aux + n) - aux;

        bool pos;
        if (u != n || aux[0] == 0) {
            pos = true;
        } else {
            pos = false;
            memset(cnt, 0, sizeof(bool) * M);
            for (int i = 1; i < (1 << n); ++i) {
                int sum = 0;
                FOR(j, 0, n) {
                    if (i & (1 << j)) {
                        sum += arr[j];
                    }
                }
                if (cnt[sum]) {
                    pos = true;
                    break;
                }
                cnt[sum] = true;
            }
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}