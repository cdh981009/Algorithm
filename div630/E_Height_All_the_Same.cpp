#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int M = 998244353;

int modPow(int a, long long b, int m) {
    if (b == 0) return 1;
    if (a == 0) return 0;
    long long h = modPow(a, b/2, m);
    h = (h*h) % m;
    if (b % 2 == 1) h = (h*a) % m;
    return h;
}
// m is a prime
int inv(int x, long long m) {
    return modPow(x, m - 2, m);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, L, R; cin >> n >> m >> L >> R;
    int x = R - L;
    int even = x/2 + 1;
    int odd = x - x/2;
    long long nm = (long long)n * m;
    if (R == L) {
        cout << 1 << "\n";
    } else {
        long long cnt = modPow(x+1, nm, M);
        cnt = (nm % 2 == 0 ? (cnt+modPow(even-odd, nm, M)) % M : cnt);
        cout << cnt << "\n";
    }
    
    return 0;
}