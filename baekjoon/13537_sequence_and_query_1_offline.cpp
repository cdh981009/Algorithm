// 13537: 수열과 쿼리 1
// https://www.acmicpc.net/problem/13537
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 101010;
const int X = 1 << 18;

int n, m;

int segN;
int seg[X];

// count tree
void constructTree() {
    for (segN = 1; segN <= n; segN <<= 1)
        ;
}

void update(int i) {
    i += segN;
    seg[i] = 1;
    while (i > 1) {
        i /= 2;
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }
}

int query(int x, int y) {
    int res = 0;

    x += segN;
    y += segN;
    while (x <= y) {
        if (x % 2 == 1) {
            res += seg[x];
            x++;
        }
        if (y % 2 == 0) {
            res += seg[y];
            y--;
        }
        x /= 2;
        y /= 2;
    }

    return res;
}

struct Nums {
    int x, i;

    bool operator<(const Nums& o) {
        return this->x > o.x;
    }
};

struct Query {
    int x, y, k, i;

    bool operator<(const Query& o) {
        return this->k > o.k;
    }
};

Nums nums[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        nums[i] = {x, i};
    }

    sort(nums, nums + n);
    constructTree();

    cin >> m;
    vector<Query> queries(m);
    vector<int> ans(m);

    FOR(i, 0, m) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;
        y--;
        queries[i] = {x, y, k, i};
    }
    sort(queries.begin(), queries.end());

    int ind = 0;
    FOR(i, 0, m) {
        auto& q = queries[i];
        while (ind < n && q.k < nums[ind].x) {
            update(nums[ind].i);
            ind++;
        }

        ans[q.i] = query(q.x, q.y);
    }
    FOR(i, 0, m) {
        cout << ans[i] << '\n';
    }
    return 0;
}