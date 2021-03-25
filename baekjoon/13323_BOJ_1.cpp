// 13323: BOJ 수열 1
// https://www.acmicpc.net/problem/13323
#include <bits/stdc++.h>

using namespace std;

#define INF (4e6 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// slope trick
// O(n log n)
// https://jwvg0425-ps.tistory.com/98

constexpr int N = 1e6;

int n;
int a[N];
long long ans;

// dp[i][x] = min(dp[i - 1][j]) (for j < x)
// ans = min(dp[n][x]) (for all x)
// dp[i] 를 x에 대한 그래프로 관리

// q에 x값이 들어 있다면 그래프 상에서 x값 이하로는 기울기가 1만큼 감소한다.
// q.top() = x인 x 에서 y가 (dp = y) 최솟값이고 그 이상으로는 기울기가 0인 직선
priority_queue<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> a[i];
    }

    q.push(a[0]);
    FOR(i, 1, n) {
        int top = q.top() + i;
        // a[i] - i 왼쪽부분 기울기를 1만큼 감소
        q.push(a[i] - i);
        if (a[i] < top) {
            // a[i] - i 오른쪽 부분 기울기를 1만큼 증가시켜야 한다
            q.pop(); // top 이 빠지면 top 왼쪽 부분 기울기가 1만큼 증가한다
            // a[i] - i 왼쪽부분의 기울기도 증가했으므로 한번 더 넣는다
            q.push(a[i] - i);
            ans += top - a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}