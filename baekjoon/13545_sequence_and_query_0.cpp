// 13545: 수열과 쿼리 0
// https://www.acmicpc.net/problem/13545
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 1;
constexpr int SN = 320; // sqrt(N)

int n, m;
int arr[N];
int ans[N];

// 환원하면 [L - 1, R]의 범위에서 Ax == Ay인 max(y - x + 1)을 찾는 문제가 된다
// Mo's algorithm + fenwick tree (max value)

struct Query {
    int l, r, i;
};

vector<Query> qs[SN];

int tree[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR_(i, 1, n) {
        cin >> arr[i];
        arr[i] += arr[i - 1]; // prefix sum
    }
    n++;

    cin >> m;
    FOR(i, 0, m) {
        int l, r;
        cin >> l >> r;
        l--;
        qs[l / SN].push_back({l, r, i});
    }

    // Mo's algorithm
    int left = 0, right = 0;
    for (auto& block : qs) {
        sort(block.begin(), block.end(), [](Query& l, Query& r) { return l.r < r.r; });
        for (auto& q : block) {
            int l = q.l;
            int r = q.r;
            int res;

            while (left > l) {

            }
            while (right < r) {

            }

            while (left < l) {

            }
            while (right > r) {
                
            }

            ans[q.i] = res;
        }
    }

    FOR(i, 0, m) {
        cout << ans[i] << '\n';
    }
    return 0;
}