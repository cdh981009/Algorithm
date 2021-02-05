// 2473: 세 용액
// https://www.acmicpc.net/problem/2239
#include <bits/stdc++.h>

using namespace std;

#define INF 3e9 + 1
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;

int arr[N];
int n;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long m = INF;
    int i1, i2, i3;

    FOR(i, 0, n) {
        FOR(j, i + 1, n) {
            int x = arr[i] + arr[j];
            int it = lower_bound(arr + j + 1, arr + n, -x) - arr;
            // self
            long long s = INF;
            int p;
            FOR_(k, it - 2, it + 2) {
                if (k >= 0 && k < n && k != i && k != j) {
                    long long ns = abs<long long>((long long)x + arr[k]);
                    if (ns < s) {
                        s = ns;
                        p = k;
                    }
                }
            }

            if (s < m) {
                m = s;
                i1 = i;
                i2 = j;
                i3 = p;
            }
        }
    }

    cout << arr[i1] << " " << arr[i2] << " " << arr[i3] << "\n";

    return 0;
}