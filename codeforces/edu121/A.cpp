#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 55;

int ans;
char arr[N];
string str;

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
        int cnt[27];
        FOR(i, 0, 27) cnt[i] = 0;
        FOR(i, 0, str.size()) {
            cnt[str[i] - 'a']++;
        }
        FOR(i, 0, 27) {
            while (cnt[i]--) {
                cout << (char)(i + 'a');
            }
        }
        cout << '\n';
    }
    return 0;
}