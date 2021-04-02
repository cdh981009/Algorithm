// 10258: Switch Array
// https://www.acmicpc.net/problem/10258
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int B = 32;
using pii = pair<int, int>;

map<pii, int> dp1;
map<pii, int> dp2;

int getDp2(int n, int bit);

int getDp1(int n, int bit) {
    if (n == B)
        return 0;
    
    auto it = dp1.find({n, bit});
    if (it != dp1.end())
        return it->second;
    
    if (bit & (1 << (B - n - 1))) {
        return dp1[{n, bit}] = getDp2(n + 1, bit) + 1 + getDp1(n + 1, 1 << (B - n - 2));
    } else {
        return getDp1(n + 1, bit);
    }
}

int getDp2(int n, int bit) {
    if (n == B)
        return 0;

    auto it = dp2.find({n, bit});
    if (it != dp2.end())
        return it->second;

    if (bit & (1 << (B - n - 1))) {
        return getDp1(n + 1, bit);
    } else {
        return dp2[{n, bit}] = getDp2(n + 1, bit) + 1 + getDp1(n + 1, 1 << (B - n - 2));
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string str; cin >> str;
        int bit = 0;
        int n = str.size();
        FOR(i, 0, n) {
            bit |= ((str[i] - '0') << (n - i - 1));
        }

        cout << getDp1(0, bit) << '\n';
    }

    return 0;
}