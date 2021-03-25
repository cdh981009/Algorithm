#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 21);
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
    segTree[ind] = val;
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
    for (::n = 1; ::n < n; ::n <<= 1)
        ;

    vector<pair<int, int>> arr(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }
    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    long long ans = 0;
    FOR(i, 0, n) {
        auto p = arr[i];
        //cout << p.first << "\n";
        ans += rangeQuery(0, p.second);
        pointUpdate(p.second, 1);
    }
    
    cout << ans << "\n";
    return 0;
}