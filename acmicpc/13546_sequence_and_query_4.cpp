// 13546: 수열과 쿼리 4
// https://www.acmicpc.net/problem/13546
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// mo's algorithm + min segment tree
// offline query
// time complexiy is O((n + q) * sqrt(n))

constexpr int N = 100001;
constexpr int X = (1 << 18);

using pii = pair<int, int>;

int n, k, q;
int arr[N];

deque<int> ind[N];

int s;
int seg[X];

void init() {
    for (s = 1; s < k; s <<= 1)
        ;
}

void update(int x) {
    int v = ind[x].empty() ? 0 : ind[x].back() - ind[x].front();
    x += s;
    seg[x] = v;

    x /= 2;

    while (x) {
        seg[x] = max(seg[2 * x], seg[2 * x + 1]);
        x /= 2;
    }
}

int query() {
    return seg[1];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    init();
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    cin >> q;
    vector<pair<pii, int>> queries(q);
    FOR(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        queries[i] = {{l, r}, i};
    }

    int block = sqrt(n);
    // 왼쪽 블록을 기준으로 정렬
    // 왼쪽 블록이 같은 경우 오른족 index를 기준으로 정렬
    sort(queries.begin(), queries.end(), [block](const pair<pii, int>& l, const pair<pii, int>& r) {
        const auto& x = l.first;
        const auto& y = r.first;
        return (x.second / block) != (y.second / block) ?
               (x.second / block) < (y.second / block) :
                x.first < y.first;
    });

    auto pushL = [](int l) {
        if (ind[arr[l]].empty() || ind[arr[l]].front() != l)
            ind[arr[l]].push_front(l);
        update(arr[l]);
    };

    auto popL = [](int l) {
        if (!ind[arr[l]].empty())
            ind[arr[l]].pop_front();
        update(arr[l]);
    };

    auto pushR = [](int r) {
        if (ind[arr[r]].empty() || ind[arr[r]].back() != r)
            ind[arr[r]].push_back(r);
        update(arr[r]);
    };

    auto popR = [](int r) {
        if (!ind[arr[r]].empty())
            ind[arr[r]].pop_back();
        update(arr[r]);
    };

    vector<int> ansVec(q);
    int l, r;
    l = r = 0;
    pushL(0);

    for (const auto& p : queries) {
        int s = p.first.first;
        int e = p.first.second;

        while (r < e)
            pushR(++r);
        while (r > e)
            popR(r--);

        while (l < s)
            popL(l++);
        while (l > s)
            pushL(--l);

        ansVec[p.second] = query();
    }

    for (auto x : ansVec)
        cout << x << '\n';

    return 0;
}