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
constexpr int sq = 315;

using pii = pair<int, int>;

int n, k, m;
int arr[N], f[N], b[N];
vector<int> ind[N];

// cnt: diff가 x인 값이 몇개 있는지 저장
// bucket: cnt를 sqrt decomposition해서 값들의 sum을 들고 있음
int cnt[N];
vector<int> bucket;

void push(int x, bool left) {
    int now;
    auto& v = ind[arr[x]];
    int num = arr[x];

    if (f[num] <= b[num]) {
        now = v[b[num]] - v[f[num]];
        cnt[now]--;
        bucket[now / sq]--;
    }

    if (left)
        f[num]--;
    else
        b[num]++;

    now = v[b[num]] - v[f[num]];
    cnt[now]++;
    bucket[now / sq]++;
}

void pop(int x, bool left) {
    int now;
    auto& v = ind[arr[x]];
    int num = arr[x];

    now = v[b[num]] - v[f[num]];
    cnt[now]--;
    bucket[now / sq]--;

    if (left)
        f[num]++;
    else
        b[num]--;

    if (f[num] <= b[num]) {
        now = v[b[num]] - v[f[num]];
        cnt[now]++;
        bucket[now / sq]++;
    }
}

struct Query {
    int s, e, i;

    bool operator<(const Query& o) {
        return s / sq != o.s / sq ? s / sq < o.s / sq : e < o.e;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(b, -1, sizeof(int) * N);

    cin >> n >> k;
    bucket = vector<int>(n / sq + 1, 0);

    FOR(i, 0, n) {
        cin >> arr[i];
        ind[arr[i]].push_back(i);
    }

    cin >> m;
    vector<Query> qs(m);
    FOR(i, 0, m) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        qs[i] = {l, r, i};
    }

    // 왼쪽 블록을 기준으로 정렬
    // 왼쪽 블록이 같은 경우 오른족 index를 기준으로 정렬
    sort(qs.begin(), qs.end());
    vector<int> ansVec(m, 0);

    int l = 0, r = 0;
    push(0, false);

    for (const auto& p : qs) {
        int s = p.s;
        int e = p.e;

        while (r < e)
            push(++r, false);
        while (l > s)
            push(--l, true);

        while (r > e)
            pop(r--, false);
        while (l < s)
            pop(l++, true);

        int ans = 0;
        ansVec[p.i] = 0;
        for (int i = bucket.size() - 1; i >= 0; --i) {
            if (bucket[i] > 0) {
                // bucket이 represent하는 cnt의 index range
                // [i * sq, (i + 1) * sq)
                for (int j = (i + 1) * sq - 1; j >= i * sq; --j) {
                    if (cnt[j] > 0) {
                        ansVec[p.i] = j;
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