#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 22);
int n;
// 1-based array
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

int kthNum(int k) {
    int ind = 1;
    while (ind < n) {
        if (segTree[2 * ind] >= k) {
            ind = 2 * ind;
        } else {
            k -= segTree[2 * ind];
            ind = 2 * ind + 1;
        }
    }
    return ind - n;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (::n = 1; ::n < 2e6 + 1; ::n <<= 1)
        ;

    int n;
    cin >> n;
    FOR(i, 0, n) {
        int q, x;
        cin >> q >> x;
        if (q == 1) {
            pointUpdate(x, 1);
        } else {
            int res = kthNum(x);
            cout << res << "\n";
            pointUpdate(res, -1);
        }
    }
    return 0;
}