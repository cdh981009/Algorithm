#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        string num; cin >> num;
        string ans;
        ll sum = 0;
        FOR(i, 0, num.size()) {
            sum += num[i] - '0';
        }

        int ins = 9 - (sum % 9);
        ins %= 9;
        // cout << ins << '\n';

        if (ins == 0) {
            ans.push_back(num[0]);
            ans.push_back('0');
            FOR(i, 1, num.size()) ans.push_back(num[i]);
        } else {
            bool done = false;
            FOR(i, 0, num.size()) {
                if (!done && (num[i] - '0' > ins)) {
                    ans.push_back(ins + '0');
                    done = true;
                }

                ans.push_back(num[i]);
            }

            if (!done) ans.push_back(ins + '0');
        }


        cout << "Case #" << caseNum << ": ";
        cout << ans << '\n';
    }

    return 0;
}