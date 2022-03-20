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
        string s1, s2; cin >> s1 >> s2;

        bool pos = true;
        ll ans = 0;

        int j = 0;
        FOR(i, 0, s2.size()) {
            if (j == s1.size()) {
                ans += s2.size() - i;
                break;
            }
            if (s1[j] == s2[i]) j++;
            else ans++;
        }

        if (j != s1.size()) pos = false;

        cout << "Case #" << caseNum << ": ";
        if (!pos)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << '\n';
    }

    return 0;
}