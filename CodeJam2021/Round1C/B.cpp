#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;
constexpr int M = 50;

using ll = unsigned long long;

int n;
string num;
string ans;

ll subNum(ll x, int s, int e) {
    ll d = 1;
    FOR(i, 0, e) {
        d *= 10;
    }
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

        for (int i = n / 2; i >= 1; --i) {
            for (int j = 0; j + i < n; j += i) {
                auto curr = num.substr(j, i);
                auto next = num.substr(j + i, i);

                if (curr >= next) {
                    
                }
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}