#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 998244353;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string str; cin >> str;
    string s;
    FOR(i, 0, str.size()) {
        char c = str[i];
        if (c == 'A') {
            s.push_back('B');
            s.push_back('B');
        } else {
            s.push_back(c);
        }
    }
    str.clear();
    FOR(i, 0, s.size()) {
        char c = s[i];
        if (c == 'B') {
            if (i + 1 < s.size() && s[i + 1] == 'B') {
                i++;
                str.push_back('A');
            } else {
                str.push_back('B');
            }
        } else {
            str.push_back('C');
        }
    }

    cout << str << '\n';

    return 0;
}