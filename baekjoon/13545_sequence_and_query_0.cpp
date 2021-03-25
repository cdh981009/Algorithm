// 13545: 수열과 쿼리 0
// https://www.acmicpc.net/problem/13545
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 100010;
constexpr int SN = 320; // sqrt(N)

int n, m;
int arr[N];
int ans[N];
vector<int> ind[2 * N];
int top[2 * N];
int btm[2 * N];

// 환원하면 [L - 1, R]의 범위에서 Ax == Ay인 max(y - x + 1)을 찾는 문제가 된다
// Mo's algorithm + sqrt decomposition (max value)

struct Query {
    int l, r, i;
};

vector<Query> qs[SN];

int cnt[N];
int bucket[SN];

void addLeft(int i) {
    int x = arr[i] + N;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]--;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]--;
    }
    btm[x]--;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]++;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]++;
    }
}

void addRight(int i) {
    int x = arr[i] + N;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]--;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]--;
    }
    top[x]++;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]++;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]++;
    }
}

void removeLeft(int i) {
    int x = arr[i] + N;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]--;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]--;
    }
    btm[x]++;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]++;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]++;
    }
}

void removeRight(int i) {
    int x = arr[i] + N;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]--;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]--;
    }
    top[x]--;
    if (top[x] >= btm[x]) {
        cnt[ind[x][top[x]] - ind[x][btm[x]]]++;
        bucket[(ind[x][top[x]] - ind[x][btm[x]]) / SN]++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ind[N].push_back(0);
    FOR_(i, 1, n) {
        cin >> arr[i];
        arr[i] += arr[i - 1]; // prefix sum
        ind[arr[i] + N].push_back(i);
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
    memset(top, -1, sizeof(int) * 2 * N);
    top[N] = 0;
    int left = 0, right = 0;
    cnt[0]++;
    bucket[0]++;
    for (auto& block : qs) {
        sort(block.begin(), block.end(), [](Query& l, Query& r) { return l.r < r.r; });
        for (auto& q : block) {
            int l = q.l;
            int r = q.r;
            int res;

            while (left > l) {
                addLeft(--left);
            }
            while (right < r) {
                addRight(++right);
            }

            while (left < l) {
                removeLeft(left++);
            }
            while (right > r) {
                removeRight(right--);
            }

            for (int i = SN - 1; i >= 0; --i) {
                if (bucket[i] > 0) {
                    for (int j = min(N - 1, (i + 1) * SN - 1); j >= i * SN; --j) {
                        if (cnt[j] > 0) {
                            res = j;
                            break;
                        }
                    }
                    break;
                }
            }
            ans[q.i] = res;
        }
    }

    FOR(i, 0, m) {
        cout << ans[i] << '\n';
    }
    return 0;
}