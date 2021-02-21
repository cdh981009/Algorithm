// 13576: Prefix와 Suffix
// https://www.acmicpc.net/problem/13576
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5 + 1;

int n;
string str;
int suffixSum[N];
int z[N];

vector<int> getZ(const string& str) {
    vector<int> z(str.size(), 0);
    int x, y = 0;

    FOR(i, 1, n) {
        // s[x ... y] = s[0 ... y - x]
        // y is the largest number possible
        if (y < i) {
            int j = 0;
            int k = i;
            while (k < n && str[j] == str[k])
                k++, j++;
            z[i] = j;
        } else if (i + z[i - x] <= y) {
            z[i] = z[i - x];
        } else { // (i + z[i - x] > y)
            int j = y + 1 - i;
            int k = y + 1;
            while (k < n && str[j] == str[k])
                k++, j++;
            z[i] = j;
        }

        if (i + z[i] - 1 > y) {
            x = i;
            y = i + z[i] - 1;
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

    vector<int> z = getZ(str);
    vector<int> ans;
    ans.push_back(n);

    FOR(i, 0, n) {
        suffixSum[z[i]]++;
        if (i + z[i] == n)
            ans.push_back(z[i]);
    }

    FOR(i, 0, n) {
        suffixSum[n - i - 1] += suffixSum[n - i];
    }

    cout << ans.size() << '\n';
    FOR(i, 0, ans.size()) {
        int x = ans[ans.size() - i - 1];
        cout << x << ' ' << suffixSum[x] + 1 << '\n';
    }
    return 0;
}