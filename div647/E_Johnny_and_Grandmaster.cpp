#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int M = (1e9 + 7);

int modPow(int a, int b, int m) {
    if (b == 0)
        return 1;
    long long h = modPow(a, b / 2, m);
    h = (h * h) % m;
    if (b % 2 == 1)
        h = (h * a) % m;
    return h;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, p; cin >> n >> p;
        vector<int> k(n);
        FOR(i, 0, n) {
            int x; cin >> x;
            k[i] = x;
        }
        if (p == 1) {
            cout << (n % 2) << "\n";
            continue;
        }
        sort(k.rbegin(), k.rend());
        // v = (realSum / p^k)
        long long v = 1;
        bool tooBig = false;
        int prevExp = k[0];
        long long result = modPow(p, k[0], M);
        for (int i = 1; i < k.size(); ++i) {
            //cout << k[i] << endl;
            int currExp = k[i];
            int deltaExp = prevExp - currExp;
            if (!tooBig) {
                for (long long j = 1; j <= min(20, deltaExp); ++j) {
                    v *= p;
                    if (v > n) {
                        tooBig = true;
                        break;
                    }
                }
            }
            long long currVal = modPow(p, currExp, M);
            if (tooBig || result > 0) {
                result = (result - currVal + M) % M;
                v--;
            } else {
                result = (result + currVal) % M;
                v++;
            }
            prevExp = currExp;
        }
        cout << result << "\n";
    }
    return 0;
}