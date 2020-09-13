#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 21);
int n;
// 1-based array
long long segTree[N];

void initTree(const vector<long long>& arr) {
    for (n = 1; n < arr.size(); n <<= 1);
    for (int i = 0; i < n; ++i) {
        segTree[i + n] = (i < arr.size() ? arr[i] : 0 /*default vaule*/);
    }
    for (int i = n - 1; i >= 1; --i) {
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }
}

void pointUpdate(int ind, long long val) {
    ind += n;
    segTree[ind] = val;
    while (ind > 1) {
        ind >>= 1;
        segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
    }
}

long long rangeQuery(int a, int b) {
    a += n;
    b += n;
    long long sum = 0;
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

    int n, m, k; cin >> n >> m >> k;
    vector<long long> arr(n);
    FOR(i, 0, n) {
        long long x; cin >> x;
        arr[i] = x;
    }

    initTree(arr);
    
    FOR(i, 0, m + k) {
        long long a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            pointUpdate(b - 1, c);
        } else {
            cout << rangeQuery(b - 1, c - 1) << "\n";
        }
    }
    return 0;
}