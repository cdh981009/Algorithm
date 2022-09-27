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

ll n, m, k, q, ans;
ll a[N];

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
        string s;
        cin >> s;
        string ans;
        vector<int> v, picked;
        rep(i, 0, s.size()) {
            int x = s[i] - '0';
            while (!v.empty() && x < v.back()) {
                picked.push_back(min(9, v.back() + 1));
                v.pop_back();
            }
            v.push_back(x);
        }
        sort(picked.begin(), picked.end());
        int j = 0;
        rep(i, 0, v.size()) {
            while (j < picked.size() && v[i] >= picked[j]) {
                ans.push_back(picked[j] + '0');
                j++;
            }
            ans.push_back(v[i] + '0');
        }
        while (j < picked.size()) {
            ans.push_back(picked[j] + '0');
            j++;
        }

        cout << ans << '\n';
    }

    return 0;
}