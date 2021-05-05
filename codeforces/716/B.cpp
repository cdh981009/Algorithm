#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10010;
constexpr int M = 1e9 + 7;

int n, k;
long long ans;

long long modpow(int a, int x, int m) {
    long long ret = 1;
    long long base = a;

    while (x) {
        if (x % 2 == 1)
            ret = (ret * base) % m;
        base = (base * base) % m;
        x /= 2;
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> k;

        cout << modpow(n, k, M) << '\n';
    }
    return 0;
}