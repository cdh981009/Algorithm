// 11001: 김치
// https://www.acmicpc.net/problem/11001
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 1; // 1e5;
int n, d;
int t[N], v[N];
long long maxVal;
//long long ans[N];

/*
// i 날 김치의 맛 최대값
// a[i] = max(v[k] + (i - k) * t[i]) for k that (i - d <= k <= i)
//
// a[i]를 결정하는 최소 k를 opt[i]라 하면
// v[k] + (i - k) * t[i] > v[k - x] + (i - k + x) * t[i] 이므로
// v[k] > v[k - x] + x * t[i] ... (1)
//
// a[i + 1]를 결정하는 opt[i + 1]를 고려하면 k = opt[i]일 때
// v[k] + (i - k + 1) * t[i + 1]과
// v[k - x] + (i - k + x + 1) * t[i + 1]를 비교하면
// (1)과 t[i] >= t[i + 1]에 의해
// v[k] > v[k - x] + x * t[i + 1]
//
// 즉 opt[i] <= opt[i + 1]
// 따라서 a[n / 2]와 opt[n / 2]를 O(d)만에 알면
// a[0] .. a[n / 2 -1]의 값은 opt[n / 2] 보다 작은 값 범위에서만 계산 해도 되고,
// a[n / 2 + 1] .. a[n]은 opt[n / 2] 보다 큰 범위에서만 계산해도 되므로
// 각 depth마다 값을 구하는데 총 O(d)만큼 걸리고
// depth는 log n 이므로
//
// time complexity 는 O(d * log n)
*/

// ans[s] 부터 ans[e] 까지 값을 구하고 값의 후보를 p부터 q까지만 확인한다
void work(int s, int e, int p, int q) {
    if (s > e)
        return;

    int mid = (s + e) / 2;

    //long long& ref = ans[mid];
    long long ans = -1;
    int opt = 0;

    FOR_(k, max(p, mid - d), min(mid, q)) {
        long long res = (long long)v[k] + (long long)(mid - k) * t[mid];
        if (res > ans) {
            opt = k;
            ans = res;
        }
    }

    maxVal = max<long long>(maxVal, ans);
    work(s, mid - 1, p, opt);
    work(mid + 1, e, opt, q);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        t[i] = x;
    }
    FOR(i, 0, n) {
        int x;
        cin >> x;
        v[i] = x;
    }

    work(0, n - 1, 0, n - 1);

    cout << maxVal << '\n';

    return 0;
}