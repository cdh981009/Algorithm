#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<long long> pre(61, 0);
    for (int i = 1; i <= 60; ++i) {
        pre[i] = 2 * pre[i - 1] + 1;
    }

    int tc; cin >> tc;
    while (tc--) {
        long long n; cin >> n;
        long long currNum = 1;
        long long pow = 1;
        long long ans = 0;
        while (n > 0) {
            while (currNum <= n) {
                currNum *= 2;
                pow++;
                //cout << "c " << currNum << " n " << n << " pow " << pow << endl;
            }
            if (currNum > n) {
                pow--;
                currNum /= 2;
            }
            n -= currNum;
            currNum = 1;
            ans += pre[pow];
            pow = 1;
        }
        cout << ans << "\n";
    }
    return 0;
}