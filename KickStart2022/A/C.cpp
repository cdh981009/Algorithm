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

constexpr int N = 51010;
constexpr int M = 100;

int n;
string str;
int dp[N][3][3][3][3][3];

bool getDp(int ind, int a1, int a2, int a3, int a4, int a5) {
    if (ind == n)
        return true;

    int& ref = dp[ind][a1][a2][a3][a4][a5];
    if (ref != -1) return ref;

    ref = false;

    if (str[ind] != '?') {
        int a6 = str[ind] - '0';
        // len of 5
        if ((a2 == a6) && (a3 == a5))
            return ref = false;
        // len of 6
        if ((a1 == a6) && (a2 == a5) && (a3 == a4))
            return ref = false;

        return ref = getDp(ind + 1, a2, a3, a4, a5, a6);
    }

    // str is '?'

    // try 0
    if (!((a2 == 0) && (a3 == a5)) && !((a1 == 0) && (a2 == a5) && (a3 == a4)))
        ref |= getDp(ind + 1, a2, a3, a4, a5, 0);

    if (!((a2 == 1) && (a3 == a5)) && !((a1 == 1) && (a2 == a5) && (a3 == a4)))
        ref |= getDp(ind + 1, a2, a3, a4, a5, 1);

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> n >> str;
        memset(dp, -1, sizeof(dp));

        bool pos = getDp(0, 2, 2, 2, 2, 2);


        cout << "Case #" << caseNum << ": ";
        cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }

    return 0;
}