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

constexpr int N = 1e3 + 10;
constexpr int M = 100;

ll n, m, k, q, ans;
vector<string> v;
set<string> s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    v = vector<string>(n);
    rep(i, 0, n) {
        string str;
        char c;
        rep(j, 0, k) {
            cin >> c;
            str.push_back(c);
        }
        v[i] = str;
        s.insert(str);
    }
    ans = 0;
    rep(i, 0, n) {
        string& pivot = v[i];
        ll cnt = 0;
        rep(j, 0, n) {
            if (i == j) continue;
            string& item = v[j];
            string target;
            rep(l, 0, k) {
                if (pivot[l] == item[l]) {
                    target.push_back(pivot[l]);
                } else {
                    int c;
                    int pc = pivot[l] - '0';
                    int ic = item[l] - '0';
                    if (pc == 0) {
                        if (ic == 1) c = 2;
                        else c = 1;
                    } else if (pc == 1) {
                        if (ic == 2) c = 0;
                        else c = 2;
                    } else {
                        if (ic == 0) c = 1;
                        else c = 0;
                    }

                    target.push_back(c + '0');
                }
            }
            //cout << target << '\n';
            if (s.count(target) != 0) cnt++;
        }

        cnt /= 2;

        //cout << cnt << '\n';
        ans += cnt * (cnt - 1) / 2;
        //cout << ans << '\n';
        //s.erase(pivot);
    }

    cout << ans << '\n';

    return 0;
}