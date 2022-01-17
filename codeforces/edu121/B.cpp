#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 55;

char arr[N];
string str;
string ans;

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
        int mx;
        int ind = 0;
        FOR(i, 0, str.size() - 1) {
            int x = str[i] - '0';
            int y = str[i + 1] - '0';
            if (x + y >= 10) {
                ind = i;
            }
        }
        
        FOR(i, 0, str.size()) {
            if (i == ind) {
                int x = str[i] - '0';
                int y = str[i + 1] - '0';
                cout << x + y;
                i++;
            } else cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}