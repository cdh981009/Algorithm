#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 2001;
constexpr int M = 100;

ll n;

string brute(string& str) {
    vector<string> strs;
    for (int i = 0; i < (1 << n); ++i) {
        string s;
        rep(j, 0, n) {
            s.push_back(str[j]);
            if ((1 << j) & i) {
                s.push_back(str[j]);
            }
        }
        strs.push_back(s);
    }

    sort(strs.begin(), strs.end());

    return strs.front();
}
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    rep_(testcase, 1, tc) {
        string str;
        cin >> str;
        n = str.size();
        string ans;
        cout << "Case #" << testcase << ": ";

        char first = -1;
        bool b = true, c = false;
        for (int i = n - 1; i >= 0; --i) {
            ans.push_back(str[i]);
            if (i == n - 1) {
                first = str[i];
            } else {
                if (b) {
                    if (first != str[i]) b = false;
                }
                if (!b) {
                    if ((str[i] < str[i + 1]) || (str[i] == str[i + 1] && c)) {
                        ans.push_back(str[i]);
                        c = true;
                    } else {
                        c = false;
                    }
                }
            }
        }

        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
        // cout << brute(str) << '\n';
    }

    return 0;
}