#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 18);
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

void p(int a, int b) {
    FOR(i, a, b) {
        cout << segTree[i + n] << " ";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        memset(segTree, 0, sizeof(int) * N);

        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> points(n);

        FOR(i, 0, n) {
            int x, y;
            cin >> x >> y;
            points[i] = {{x, y}, 0};
        }
        // x sort
        sort(points.begin(), points.end());

        // index compression
        int cnt = 0;
        FOR(i, 1, n) {
            if (points[i].first.first != points[i - 1].first.first) {
                ++cnt;
            }
            points[i].second = cnt;
        }

        for (::n = 1; ::n < cnt + 1; ::n <<= 1)
            ;

        // y sort
        sort(points.begin(), points.end(),
                [](const pair<pair<int, int>, int>& l, const pair<pair<int, int>, int>& r) {
                    return (l.first.second != r.first.second ? l.first.second < r.first.second : l.first.first > r.first.first);
                });

        long long ans = 0;
        FOR(i, 0, n) {
            ans += rangeQuery(points[i].second, cnt);
            // update
            pointUpdate(points[i].second, 1);
        }

        cout << ans << "\n";
    }
    return 0;
}