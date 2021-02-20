// 13546: 수열과 쿼리 4
// https://www.acmicpc.net/problem/13546
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// mo's algorithm + sqrt decomposition
// offline query
// time complexiy is O(n * sqrt(n))

constexpr int N = 101010;

using pii = pair<int, int>;

int n, k, q;
int block;
int arr[N];

deque<int> ind[N];

// cnt: diff가 x인 값이 몇개 있는지 저장
// bucket: cnt를 sqrt decomposition해서 값들의 sum을 들고 있음
int cnt[N];
vector<int> bucket;

void push(int x, bool left) {
    int now;
    auto& dq = ind[arr[x]];

    if (!dq.empty()) {
        now = dq.back() - dq.front();
        cnt[now]--;
        bucket[now / block]--;
    }

    if (left)
        dq.push_front(x);
    else
        dq.push_back(x);

    now = dq.back() - dq.front();
    cnt[now]++;
    bucket[now / block]++;
}

void pop(int x, bool left) {
    int now;
    auto& dq = ind[arr[x]];

    now = dq.back() - dq.front();
    cnt[now]--;
    bucket[now / block]--;

    if (left)
        dq.pop_front();
    else
        dq.pop_back();

    if (!dq.empty()) {
        now = dq.back() - dq.front();
        cnt[now]++;
        bucket[now / block]++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    block = sqrt(n);
    bucket = vector<int>(n / block + 2, 0);

    FOR(i, 0, n)
        cin >> arr[i];

    cin >> q;
    vector<pair<pii, int>> queries(q);
    FOR(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        queries[i] = {{l, r}, i};
    }

    // 왼쪽 블록을 기준으로 정렬
    // 왼쪽 블록이 같은 경우 오른족 index를 기준으로 정렬
    sort(queries.begin(), queries.end(), [](const pair<pii, int>& l, const pair<pii, int>& r) {
        const auto& x = l.first;
        const auto& y = r.first;
        return (x.second / block) != (y.second / block) ? (x.second / block) < (y.second / block) : x.first < y.first;
    });

    vector<int> ansVec(q, 0);

    int l, r;
    l = queries[0].first.first;
    r = queries[0].first.second;
    FOR_(i, l, r)
        push(i, false);

    for (const auto& p : queries) {
        int s = p.first.first;
        int e = p.first.second;

        while (r < e)
            push(++r, false);
        while (l > s)
            push(--l, true);

        while (r > e)
            pop(r--, false);
        while (l < s)
            pop(l++, true);

        int ans = 0;
        ansVec[p.second] = 0;
        for (int i = bucket.size() - 1; i >= 0; --i) {
            if (bucket[i] > 0) {
                // bucket이 represent하는 cnt의 index range
                // [i * block, (i + 1) * block)
                for (int j = (i + 1) * block - 1; j >= i * block; --j) {
                    if (cnt[j] > 0) {
                        ansVec[p.second] = j;
                        break;
                    }
                }
                break;
            }
        }
    }

    for (auto x : ansVec)
        cout << x << '\n';

    return 0;
}