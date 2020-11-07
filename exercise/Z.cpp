// 13713: 문자열과 쿼리
// https://www.acmicpc.net/problem/13713
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// z algorithm;
vector<int> getZ(const string& s) {
    vector<int> z(s.size(), 0);

    int x = 0;
    int y = 0; //

    FOR(i, 1, s.size()) {
        if (i > y) {
            int j = 0;
            while (i + j < s.size() && s[j] == s[i + j]) {
                z[i]++;
                j++;
            }
        } else if (i + z[i - x] <= y) {
            z[i] = z[i - x];
        } else /* if (i + z[i - x] > y) */ {
            z[i] = y - i + 1;
            int j = y + 1;
            while (j < s.size() && s[j] == s[j - i]) {
                z[i]++;
                j++;
            }
        }

        if (i + z[i] - 1 > y) {
            y = i + z[i] - 1;
            x = i;
        }
    }

    return z;
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    reverse(str.begin(), str.end());

    auto z = getZ(str);
    z[0] = str.size();

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        cout << z[str.size() - 1 - x] << '\n';
    }

    return 0;
}