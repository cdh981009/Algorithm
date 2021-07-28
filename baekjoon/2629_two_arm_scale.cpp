// 2629: 양팔저울
// https://www.acmicpc.net/problem/2629
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 31;
constexpr int M = 30010;
constexpr int L = 15000;

int n, k;
int arr[N];
bool dp[N][M];
bool memoi[N][M];

bool getDp(int i, int w) {
    if (i == 0)
        return w == 0;

    bool& ref = dp[i][w + L];
    if (memoi[i][w + L])
        return ref;
    memoi[i][w + L] = true;

    return ref = getDp(i - 1, w) || getDp(i - 1, w + arr[i - 1]) || getDp(i - 1, w - arr[i - 1]);
}

int main() {
    #ifndef BOJ
    freopen("input.txt", "r", stdin);
    #endif

    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    cin >> k;
    FOR(i, 0, k) {
        int x; cin >> x;
        bool pos;
        if (x > 15000) {
            pos = false;
        } else {
            pos = getDp(n, x);
        }
        cout << (pos ? 'Y' : 'N') << ' ';
    }
    cout << '\n';

    return 0;
}