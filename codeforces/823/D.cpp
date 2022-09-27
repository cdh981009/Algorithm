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

constexpr int N = 300;
constexpr int M = 100;

string s1, s2;
int t;

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
        cin >> t;
        int n;
        cin >> s1 >> s2;
        n = s1.size();
        reverse(s1.begin(), s1.end());
        bool pos = true;

        map<pair<int, int>, int> mp;
        rep(i, 0, n) {
            if (s1[i] > s2[i]) swap(s1[i], s2[i]);

            mp[{s1[i], s2[i]}]++;
        }

        bool one = true;
        for (auto &[k, v] : mp) {
            if (v % 2 == 1) {
                if (k.first != k.second) {
                    pos = false;
                } else {
                    if (one) {
                        one = false;
                    } else {
                        pos = false;
                    }
                }
            }
        }

        printYN(pos);
    }

    return 0;
}