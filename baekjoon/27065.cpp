#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 5010;
constexpr int M = 100;

ll n, m, k, q, ans;
int number[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    rep(i, 1, N) {
        int j = 1;
        ll sum = 0;
        while (j * j <= i) {
            if (i != j && i % j == 0) {  // divisor
                sum += j;
                if (i / j != j && i / j != i)
                    sum += i / j;
            }
            j++;
        }

        if (sum == i)
            number[i] = 0;
        else if (sum < i)
            number[i] = -1;
        else
            number[i] = 1;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        bool boj = true;

        if (number[n] == 1) {
            boj = false;
            int i = 1;
            while (i * i <= n) {
                if (n % i == 0) {
                    if ((i != n && number[i] == 1) || 
                        (n / i != n && number[n / i] == 1)) {
                        boj = true;
                    }
                }
                i++;
            }
        }

        if (boj)
            cout << "BOJ 2022";
        else
            cout << "Good Bye";
        cout << '\n';
    }

    return 0;
}