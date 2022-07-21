#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
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
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 51;
constexpr int M = 100;

ll n, m, k, q, ans;
ll arr[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        string str;
        cin >> str;
        bool pos = true;
        n = str.size();
        vector<int> pre(n, 0), suf(n, INF);
        rep(i, 0, n) {
            int x = 0;
            if (str[i] == '(') {
                x = 1;
            } else if (str[i] == ')') {
                x = -1;
            }
            pre[i] = (i == 0 ? 0 : pre[i-1]) + x;
        }
        suf[n-1] = pre[n-1];
        for (int i = n -2; i >=0; --i) {
            suf[i] = min(pre[i], suf[i+1]);
        }

        int add = 0;
        int rm = INF;
        int prev = -1;
        rep(i, 0, n) {
            if (str[i] == '?') {
                int mn = suf[i] + add;
                if (mn >= 1) {
                    add--;
                    if (prev == 1 && rm >= 2) {
                        pos = false;
                        break;
                    }
                    prev = 0;
                    rm = INF;
                } else {
                    add++;
                    if (prev == 0) {
                        pos = false;
                        break;
                    }
                    prev = 1;
                    rm = INF;
                }
            }
            rm = min(rm, pre[i] + add);
            
        }

        printYN(pos);
    }

    return 0;
}