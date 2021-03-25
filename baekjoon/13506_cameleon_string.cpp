// 13506: 카멜레온 문자열
// https://www.acmicpc.net/problem/13506
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6 + 1;

int n;
string str;
int cnt[N];

// Z algorithm, string's border
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

    cin >> str;
    n = str.size();

    auto z = getZ(str);

    FOR(i, 0, n) {
        cnt[z[i]]++;
    }
    for (int i = n - 1; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }

    int ans = -1;
    FOR(i, 0, n) {
        if (z[i] + i == n && cnt[z[i]] >= 2) {
            ans = max(z[i], ans);
        }
    }

    if (ans == -1) {
        cout << ans << '\n';
    } else {
        cout << str.substr(0, ans) << '\n';
    }

    return 0;
}