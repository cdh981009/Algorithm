#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5 + 10;
constexpr int M = 1e9 + 7;

int arr[N];
int n;

using ll = long long;
ll fact[N];

void init() {
    fact[0] = 1;
    FOR(i, 1, N) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= M;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> arr[0];
        int a = arr[0];
        FOR(i, 1, n) {
            cin >> arr[i];
            a &= arr[i];
        }

        ll cnt = 0;
        FOR(i, 0, n) {
            if (arr[i] == a)
                cnt++;
        }
        
        ll x = cnt * (cnt - 1);
        x %= M;

        cout << (x * fact[n - 2]) % M << '\n';
    }
    return 0;
}