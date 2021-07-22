#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301010;

int n, m;
int arr[N];
int aux[N];
int indOf[N];
int kCand[N];
int ans[N];
int cnt;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cnt = 0;

        cin >> n >> m;
        memset(kCand, 0, sizeof(int) * n);
        FOR(i, 0, n) {
            cin >> arr[i];
            arr[i]--;
            kCand[(i - arr[i] + n) % n]++;
        }

        FOR(i, 0, n) {
            if (kCand[i] >= n - (2 * m)) {
                int k = i;
                memcpy(aux, arr, sizeof(int) * n);
                FOR(j, 0, n) {
                    indOf[aux[j]] = j;
                }
                int s = 0;
                FOR(j, 0, n) {
                    if (aux[j] != (j - k + n) % n) {
                        s++;
                        int a = aux[j];
                        int b = aux[indOf[(j - k + n) % n]];
                        swap(aux[j], aux[indOf[(j - k + n) % n]]);
                        swap(indOf[a], indOf[b]);
                    }
                }

                if (s <= m) {
                    ans[cnt] = k;
                    cnt++;
                }
            }
        }

        cout << cnt << ' ';
        FOR(i, 0, cnt) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}