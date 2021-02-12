// 7469: K-th Number
// https://www.acmicpc.net/problem/7469
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
constexpr int X = 18;

int n, m;
int arr[N];
int sz;
vector<int> seg[1 << X];

// merge sort tree
void init() {
    // smallest 2^x that is greater than or equal to n
    for (sz = 1; sz < n; sz <<= 1);

    // leaf
    FOR(i, 0, sz) {
        seg[i + sz].push_back(i < n ? arr[i] : INF);
    }

    for (int i = sz - 1; i >= 1; --i) {
        seg[i].resize(seg[2 * i].size() * 2);
        merge(seg[2 * i].begin(),     seg[2 * i].end(),
              seg[2 * i + 1].begin(), seg[2 * i + 1].end(),
              seg[i].begin());
    }
}

// s, e구간에 있는 숫자중 x보다 작거나 같은 것의 갯수
int cntLE(int s, int e, int x) {
    s += sz;
    e += sz;

    int cnt = 0;

    while (s <= e) {
        if (s % 2 == 1) {
            cnt += upper_bound(seg[s].begin(), seg[s].end(), x) - seg[s].begin();
            s++;
        }
        if (e % 2 == 0) {
            cnt += upper_bound(seg[e].begin(), seg[e].end(), x) - seg[e].begin();
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return cnt;
}

// O(log^3 n)
int query(int s, int e, int k) {
    // parametric search with check function of time complexity O(logn logn)
    int maxN = n;
    int x = -1;
    for (int step = maxN; step >= 1; step /= 2) {
        while (x + step < n && cntLE(s, e, seg[1][x + step]) < k)
            x += step;
    }

    x++;

    return seg[1][x];
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    init();

    FOR(i, 0, m) {
        int a, b, k;
        cin >> a >> b >> k;
        a--; b--;
        cout << query(a, b, k) << '\n'; 
    }

    return 0;
}