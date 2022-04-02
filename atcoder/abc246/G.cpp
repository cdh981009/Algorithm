#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 201010;
constexpr int M = 998244353;

ll n, l, x;

vi edges[N];
ll a[N];

// parametric search: 각 player가 최선의 선택을 해서, takahashi가 x 이상의 점수를 얻을 수 있나?
// x에 대해 parametric search: x 이상의 점수를 얻을 수 있다면 y < x인 y에 대해 y 이상의 점수도 당연히 얻을 수 있으므로.
// 이제 각 vertex에 적힌 숫자를 x보다 큰거나 같은것(검은색)과 작은것(흰색)으로 나눠서 생각
// tree dp: dp[node] := node에서 게임을 시작할 때, aoki가 아무리 최선으로 플레이 해도, dp[node]만큼의 검은색을 흰색으로 바꿔야만 이길 수 있다

// dp[node] = 0 <=> aoki가 무조건 이긴다. 따라서, takahashi가 x 이상의 점수를 얻을 수 있나? <=> dp[root] != 0 인가?
// node가 검은색이면 시작하자마자 takahashi가 이기므로 dp[node] += 1. 무조건 이 노드를 흰색으로 바꿔야만 한다.
// node가 흰색 이라도, node의 자식들 중 하나라도 dp[child] > 0 이면, 맨 처음 aoki가 게임의 규칙에 의해 바꿀 수 있는 노드 한개를 제외하면,
// 그 child로 takahashi가 이동하면 aoki는 질 수 밖에 없다. 따라서, dp[node] = max((sum of dp[child]) - 1 , 0) + black[node]
// 이 때 -1 의 의미는, 게임 시작 후 takahashi가 이동하기 전에 aoki가 게임의 규칙에 의해 바꿀 수 있는 노드 한개.

// 예시) 노드가 흰색. 자식중 단 하나만 dp[child] = 2이고 나머지는 0이면,
// 하나만 흰색으로 바꿀 수 있다면 나머지 하나는 규칙을 사용해 흰색으로 바꾸면 됨
// 따라서 dp[node] = 1;
// 만약 자식중 두개가 dp[child] = 1이면, 어느 것을 규칙을 사용해 흰색으로 바꾸든, takahashi가 다른 한쪽으로 가면 이김.
// 따라서 나머지 하나도 흰색으로 바꿔주어야 함. => dp[node] = 1 + 1 - 1 = 1

// 얻는 숫자가 0인 경우도 있으므로 parametric search시 주의

int dfs(int node, int par, int val) {
    int dp = a[node] >= val;
    
    int sum = 0;
    for (auto & c : edges[node]) {
        if (c == par) continue;
        sum += dfs(c, node, val);
    }
    if (sum > 0)
        sum -= 1;

    return dp + sum;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a[0] = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // do parametric search
    int mx = 1000000000;
    int b = 0;

    for (int step = mx; step >= 1; step /= 2) {
        while (b + step <= mx && dfs(0, -1, b + step)) b += step;
    }

    cout << b << '\n';

    return 0;
}