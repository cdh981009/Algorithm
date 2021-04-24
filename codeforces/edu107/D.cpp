#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e5;
constexpr int M = 26;

int n, k;
int arr[N];
int cnt[M][M];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    int a = 0;
    int b = 0;
    bool first = true;
    bool primary = true;
    int i = 0;
    while (i < k * k) {
        if (first) {
            arr[i++] = a;
            first = false;
        } else if (primary) {
            primary = false;
            arr[i++] = a;
        } else {
            primary = true;
            arr[i++] = ++b;
            if (b == k - 1) {
                a++;
                b = a;
                first = true;
            }
        }
    }   

    FOR(i, 0, n) {
        cout << (char)('a' + arr[i % (k * k)]);
    }
    cout << '\n';

    return 0;
}