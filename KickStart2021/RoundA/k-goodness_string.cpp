#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n, k;
int ans;
string str;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        cin >> n >> k;
        cin >> str;
    
        int diff = 0;
        FOR(i, 0, n / 2) {
            if (str[i] != str[n - i - 1])
                diff++;
        }

        ans = abs(k - diff);

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}