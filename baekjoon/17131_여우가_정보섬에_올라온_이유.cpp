// 17131: 여우가 정보섬에 올라온 이유
// https : //www.acmicpc.net/problem/17131
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 20);
constexpr int M = 1e9 + 7;
int n;
// 1-based array
// sum query segTree
int segTree[N];

void initTree(const vector<int>& arr) {
    for (n = 1; n < arr.size(); n <<= 1)
        ;
    for (int i = 0; i < n; ++i) {
        segTree[i + n] = (i < arr.size() ? arr[i] : 0 /*default vaule*/);
    }
    for (int i = n - 1; i >= 1; --i) {
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }
}

void pointUpdate(int ind, int val) {
    ind += n;
    segTree[ind] += val;
    while (ind > 1) {
        ind >>= 1;
        segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
    }
}

int rangeQuery(int a, int b) {
    a += n;
    b += n;
    int sum = 0;
    while (a <= b) {
        if (a % 2 == 1) // odd
            sum += segTree[a++];
        if (b % 2 == 0) // even
            sum += segTree[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    // 1. y 좌표 기준 정렬
    // 2. y 좌표 기준 큰 수 부터 segTree에 넣으며 쿼리
    // 2-1. 이 때 y좌표가 달라질 때 한거번에 segTree에 업데이트 해야함
    // 3. segTree는 x좌표를 index로 저장함 (가장 작은수가 0이 되도록 + 2e5)
    // 4. 어떤 점보다 x 좌표가 작은것의 수, 큰 것의 수를 구해 곱하면
    //    그 점이 중심이 되는 V 별자리의 갯수
    // 5. mod 연산후 합해 출력
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        points[i] = {y, x + 2e5};
    }
    // y sort
    sort(points.rbegin(), points.rend());

    for (::n = 1; ::n < 4e5 + 1; ::n <<= 1)
        ;

    long long ans = 0;
    vector<int> updateStack;
    int prevY = INF;

    FOR(i, 0, n) {
        // update
        if (points[i].first != prevY) {
            for (auto x : updateStack) {
                pointUpdate(points[x].second, 1);
            }
            updateStack.clear();
        }
        prevY = points[i].first;
        updateStack.push_back(i);

        long long left = rangeQuery(0, points[i].second - 1);
        long long right = rangeQuery(points[i].second + 1, 4e5);
        ans += (left * right) % M;
        ans %= M;
    }

    cout << ans << "\n";

    return 0;
}