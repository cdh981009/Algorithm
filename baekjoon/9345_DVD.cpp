#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 20);
int n;
// 1-based array
int minSegTree[N];
int maxSegTree[N];

void initTree(const vector<int>& arr) {
    for (n = 1; n < arr.size(); n <<= 1)
        ;
    for (int i = 0; i < n; ++i) {
        minSegTree[i + n] = (i < arr.size() ? arr[i] : INF /*default vaule*/);
        maxSegTree[i + n] = (i < arr.size() ? arr[i] : 0 /*default vaule*/);
    }
    for (int i = n - 1; i >= 1; --i) {
        minSegTree[i] = min(minSegTree[2 * i], minSegTree[2 * i + 1]);
        maxSegTree[i] = max(maxSegTree[2 * i], maxSegTree[2 * i + 1]);
    }
}

void pointUpdate(int ind, int val) {
    ind += n;
    maxSegTree[ind] = val;
    minSegTree[ind] = val;
    while (ind > 1) {
        ind >>= 1;
        maxSegTree[ind] = max(maxSegTree[2 * ind], maxSegTree[2 * ind + 1]);
        minSegTree[ind] = min(minSegTree[2 * ind], minSegTree[2 * ind + 1]);
    }
}

pair<int, int> rangeQuery(int a, int b) {
    a += n;
    b += n;
    int minV = INF;
    int maxV = 0;
    while (a <= b) {
        if (a % 2 == 1) { // odd
            minV = min(minV, minSegTree[a]);
            maxV = max(maxV, maxSegTree[a]);
            a++;
        }
        if (b % 2 == 0) { // even
            minV = min(minV, minSegTree[b]);
            maxV = max(maxV, maxSegTree[b]);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return {minV, maxV};
}

/*
void p(int a, int b) {
    FOR(i, a, b) {
        cout << maxSegTree[i + n] << " ";
    }
    cout << "\n";
}
*/

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        FOR(i, 0, n) {
            arr[i] = i;
        }

        initTree(arr);

        FOR(i, 0, k) {
            int q, a, b;
            cin >> q >> a >> b;
            if (q == 0) {
                swap(arr[a], arr[b]);
                pointUpdate(a, arr[a]);
                pointUpdate(b, arr[b]);
            } else {
                auto res = rangeQuery(a, b);
                cout << ((res.first == a && res.second == b) ? "YES" : "NO") << "\n";
            }
        }
    }
    return 0;
}