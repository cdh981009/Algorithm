#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        ll ans, n;
        string s, t;
        cin >> n >> s >> t;
        string cs, ct;

        FOR(i, 0, n) {
            if (s[i] != 'b') cs += s[i];
            if (t[i] != 'b') ct += t[i];
        }

        bool pos = cs == ct;

        if (pos) {
            for (int i = 0, j = 0; i < n; ++i) {
                if (s[i] == 'a') {
                    while (j < i) {
                        if (t[j] == 'a') pos = false;
                        j++;
                    }

                    while (j < n) {
                        if (t[j++] == 'a') break;
                    }
                }
            }

            for (int i = n - 1, j = n - 1; i >= 0; --i) {
                if (s[i] == 'c') {
                    while (j > i) {
                        if (t[j] == 'c') pos = false;
                        j--;
                    }

                    while (j >= 0) {
                        if (t[j--] == 'c') break;
                    }
                }
            }
        }

        printYN(pos);
    }

    return 0;
}