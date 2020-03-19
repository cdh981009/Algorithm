#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> x;
    vector<int> y;
    FOR(i, 0, n) {
        int b; cin >> b;
        x.push_back(b);
    }
    FOR(i, 0, m) {
        int b; cin >> b;
        y.push_back(b);
    }
    vector<int> divisor;
    for (int i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            divisor.push_back(i);
            if (i * i != k)
                divisor.push_back(k / i);
        }
    }
    long long ans = 0;
    for (auto d : divisor) {
        int lenX = d, lenY = k / d;
        int cntX = 0, cntY = 0;
        int consec1 = 0;
        FOR(i, 0, n) {
            consec1 = (x[i] == 0)? 0 : (consec1+1);
            cntX += (consec1 >= lenX ? 1 : 0);
        }
        consec1 = 0;
        FOR(i, 0, m) {
            consec1 = (y[i] == 0) ? 0 : (consec1+1);
            cntY += (consec1 >= lenY ? 1 : 0);
        }
        long long += cntX * cntY;
    }
    cout << ans << "\n";
    return 0;
}