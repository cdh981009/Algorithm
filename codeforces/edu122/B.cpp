#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
int n;

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
        ans = 0;
        string str;
        cin >> str;
        int z, o;
        z = o = 0;
        FOR(i, 0, str.size()) {
            if (str[i] == '0') o++;
            else z++;
        }
        if (z == o) {
            if (str[0] == '0') ans = z - 1;
            else ans = o - 1;
        } else {
            ans = min(z, o);
        }

        cout << ans << '\n';
    }
    return 0;
}