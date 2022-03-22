#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

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
        int n;
        cin >> n;
        string str; cin >> str;
        int ind = 0;
        int cnt = 0;

        int o = 0;
        bool regular = true;
        vi stk;
        FOR(i, 0, n) {
            if (str[i] == '(') o++;
            else o--;
            if (o == -1) regular = false;

            bool pal = false;

            if (stk.empty()) stk.push_back(str[i]);
            else if (stk.size() == 1) {
                if (stk.back() == str[i]) pal = true;
                else stk.push_back(str[i]);
            } else {
                if (stk.back() == str[i]) stk.pop_back();
                else pal = true;
            }

            if ((o == 0 && regular) || (pal)) {
                regular = true;
                stk.clear();
                o = 0;
                cnt++;
                ind = i + 1;
            }
        }


        cout << cnt << ' ' << n - ind << '\n';
    }

    return 0;
}