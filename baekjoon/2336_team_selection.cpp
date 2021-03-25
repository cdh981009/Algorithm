// 2336: Team Selection
// https://www.acmicpc.net/problem/2336
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e5 + 1;
constexpr int X = (1 << 20);

int x, n;
int seg[X];

// v1을 작아지는 순서로 정렬했을 때 순서대로 segtree에서 값을 뺀다.
// (v1이 나보다 더 작은 항목만 본다는 뜻)
// v2는 segtree의 index값이다. query를 이보다 작은 위치에서 날린다.
// (v2가 나보다 더 작은 항목만 본다는 뜻)
// segtree의 값은 v3의 값이다. query는 min query 이다.
// (v1, v2가 모두 나보다 더 작은 항목 중 하나라도 나보다 v3가 작은 항목이 있다면 나는 excellent 하지 않다)

void pointUpdate(int ind, int val) {
    ind += n;
    seg[ind] = val;
    while (ind > 1) {
        ind >>= 1;
        seg[ind] = min(seg[2 * ind], seg[2 * ind + 1]);
    }
}

int rangeQuery(int a, int b) {
    a += n;
    b += n;
    int ret = INF;
    while (a <= b) {
        if (a % 2 == 1)
            ret = min(ret, seg[a++]);
        if (b % 2 == 0)
            ret = min(ret, seg[b--]);
        a /= 2;
        b /= 2;
    }
    return ret;
}

struct Nums {
    int a, b, c;
    bool operator<(const Nums& o) {
        return a > o.a;
    }
} nums[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int y;
    cin >> x;
    FOR(i, 0, x) {
        cin >> y;
        nums[--y].a = i;
    }
    FOR(i, 0, x) {
        cin >> y;
        nums[--y].b = i;
    }
    FOR(i, 0, x) {
        cin >> y;
        nums[--y].c = i;
    }

    sort(nums, nums + x);

    int ans = x;

    // min tree
    for (n = 1; n < x; n <<= 1)
        ;
    for (int i = 0; i < x; ++i)
        seg[nums[i].b + n] = nums[i].c;
    for (int i = x; i < n; ++i)
        seg[i + n] = INF;
    for (int i = n - 1; i >= 1; --i)
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    
    FOR(i, 0, x) {
        // 나보다 better인 학생이 있다면 나는 excellent하지 않다
        ans -= rangeQuery(0, nums[i].b) < nums[i].c;
        pointUpdate(nums[i].b, INF);
    }

    cout << ans << '\n';

    return 0;
}