// 2305: 자리 배치
// https://www.acmicpc.net/problem/2305
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 40;

int n, k;

int dpFull[N][N];
int dpEmpty[N][N][N];

// 그 전까진 잘 채워져 있다고 하고 s번째 사람이 앉음
// [s, e]에 빈자리가 없음
int getFull(int s, int e) {
    if (s > e)
        return 1;
    
    int &ref = dpFull[s][e];

    if (ref != -1)
        return ref;

    ref = 0;

    // 내 자리에 얌전히 앉음
    ref += getFull(s + 1, e);
    // 오른쪽에 자리가 있다면 교환해서 앉음
    if (s + 1 <= e)
        ref += getFull(s + 2, e);

    return ref;
}

// 그 전까진 잘 채워져 있다고 하고 s번째 사람이 앉음
// [s, e]중 x에 빈자리가 있음
int getEmpty(int x, int s, int e) {
    if (s > e)
        return 1;

    int &ref = dpEmpty[x][s][e];

    if (ref != -1)
        return ref;

    ref = 0;

    // 빈자리가 이미 지나감
    if (x < s)
        return ref = getFull(s, e);

    // 현재 자리가 빈자리임
    if (s == x) {
        // 오른쪽 사람이 와서 앉았음
        if (s + 1 <= e)
            ref += getEmpty(s + 1, s + 1, e);
        // 그냥 비워놓음
        ref += getFull(s + 1, e);
    } else {
        // 현재 자리가 빈자리가 아님

        // 1. 내 자리에 얌전히 앉음
        ref += getEmpty(x, s + 1, e);

        // 2. 오른쪽 사람이랑 교환해서 앉음
        if (s + 1 <= e && s + 1 != x)
            ref += getEmpty(x, s + 2, e);
        
        // 3. 오른쪽 사람을 밀쳐내고 앉음 
        // 오른쪽 이후 사람은 빈 자리가 있을 때 까지 쭉 밀려남
        // 빈 자리를 채우고 그 이후에 채우게 됨
        if (s + 1 <= e)
            ref += getFull(x + 1, e);
    }

    return ref;
}

int solve() {
    int cnt = 0;
    // i번째 사람이 자유석에 앉음
    FOR(i, 0, n) {
        if (i == k) {
            cnt += getFull(0, k - 1) * getFull(k + 1, n - 1);
        } else if (i < k) {
            cnt += (getFull(k + 1, n - 1) * getEmpty(i, 0, k - 1));
        } else {
            cnt += (getFull(0, k - 1) * getEmpty(i, k + 1, n - 1));
        }
    }

    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dpFull, -1, sizeof(int) * N * N);
    memset(dpEmpty, -1, sizeof(int) * N * N * N);

    cin >> n >> k;
    k--;

    cout << solve() << endl;
    return 0;
}