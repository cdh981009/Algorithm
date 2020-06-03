#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int minFactor[(int)1e6 + 1];

void init() {
    FOR(i, 0, 1e6 + 1)
        minFactor[i] = i;
    for (int i = 2; i * i <= 1e6 + 1; ++i) {
        if (minFactor[i] == i) {
            for (int j = i * i; j <= 1e6 + 1; j += i) {
                if (minFactor[j] == j)
                    minFactor[j] = i;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    init();

    int tc; cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        if (n % 2 == 0) {
            cout << n + (k * 2) << "\n";
        } else {
            cout << n + minFactor[n] + (k - 1) * 2 << "\n";
        }
    }
    return 0;
}