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

constexpr int N = 1030;
constexpr int M = 100;

string str, ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    vector<char> v;
    rep(i, 0, str.size()) {
        char c = str[i];
        if (isalpha(c)) {
            ans.push_back(c);
        } else if (c == '(') {
            v.push_back(c);
        } else if (c == ')') {
            while (v.back() != '(') {
                ans.push_back(v.back());
                v.pop_back();
            }
            v.pop_back();
        } else {
            if (c == '+' || c == '-') {
                while (!v.empty() && v.back() != '(') {
                    ans.push_back(v.back());
                    v.pop_back();
                }
            } else {
                while (!v.empty() && v.back() != '(' && v.back() != '+' && v.back() != '-') {
                    ans.push_back(v.back());
                    v.pop_back();
                }
            }
            v.push_back(c);
        }
    }
    while (!v.empty()) {
        ans.push_back(v.back());
        v.pop_back();
    }

    cout << ans << '\n';

    return 0;
}