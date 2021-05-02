#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;
constexpr int M = 50;

using ll = long long;

int n;
string num;

bool cmp(const string& l, const string& r) {
    return (l.size() == r.size()) ? l < r : l.size() < r.size();
}

string f(int n, ll x) {
    // concat x, x + 1, x + 2, ... n times
    string ret;
    FOR(i, 0, n) {
        ret += to_string(x++);
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> num;
        n = num.size();

        string ans = string(20, '9');

        FOR_(i, 2, 19) {
            // parametric search
            ll maxV = 2e9;
            ll x = maxV;
            for (ll step = maxV; step >= 1; step /= 2) {
                while (x - step >= 1 && cmp(num, f(i, x - step)))
                    x -= step;
            }
            string res = f(i, x);

            if (cmp(res, ans)) {
                ans = res;
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}