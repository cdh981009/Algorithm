// 16287: Parcel
// https://www.acmicpc.net/problem/16287
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e3;
constexpr int M = 4e5 + 10;

int w, n;

int arr[N];
int p[M];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> w >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    FOR(i, 0, n) {
        FOR(j, 0, i) {
            p[arr[i] + arr[j]] = max(p[arr[i] + arr[j]], j);
        }
    }

    // FOR(i, 0, 50) {
    //     cout << i << ' ' << p[i] << '\n';
    // }
    // cout << '\n';

    bool ans = false;
    FOR(i, 0, n) {
        FOR(j, 0, i) {
            int num = w - (arr[i] + arr[j]);
            // cout << num << ' ' << p[num] << '\n';
            if (num > 0 && num < M && p [num] > i) {
                ans = true;
                break;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}