#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
string str;
int ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> str;
        ans = 0;
        bool prev = false;
        FOR(i, 0, str.size()) {
            if (str[i] == '0' && !prev) {
                prev = true;
                ans++;
            } 
            if (str[i] == '1') {
                prev = false;
            }
        }

        cout << min(2, ans) << '\n';
    }
    return 0;
}