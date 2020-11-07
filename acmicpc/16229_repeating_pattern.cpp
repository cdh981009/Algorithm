// 16229: 반복 패턴
// https://www.acmicpc.net/problem/16229
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> getZ(const vector<char>& str) {
    vector<int> z(str.size(), 0);

    int x = 0;
    int y = 0;
    FOR(i, 1, str.size()) {
        if (i > y) {
            int j = 0;
            while (str[i + j] == str[j]) {
                j++;
                z[i]++;
            }
        } else if (i + z[i - x] <= y) {
            z[i] = z[i - x];
        } else {
            z[i] = y - i + 1;

            int j = y + 1;
            while (str[j] == str[j - i]) {
                j++;
                z[i]++;
            }
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

    int n, k;
    cin >> n >> k;
    vector<char> str(n + 1);
    FOR(i, 0, n) {
        char c;
        cin >> c;
        str[i] = c;
    }
    str[n] = '#';

    if (k >= n) {
        cout << n << '\n';
    } else {
        auto z = getZ(str);

        int maxLen = 0;
        FOR(i, 1, n) {
            if (i + z[i] == n && (i - (n % i)) % i <= k) {
                // str[0 ... i - 1] 를 패턴으로 할 수 있는지 확인한다.
                // i + z[i] == n: 뒤에 i 보다 작은수의 임의의 문자를 붙혀 반복되게 만들 수 있다.
                // i - (n % i): 필요한 임의의 문자의 길이
                // % i하는 이유: 이미 문자열 자체가 반복패턴 일 경우, 필요한 문자의 길이가 0이다

                maxLen = max(maxLen, i);
            }
        }

        cout << maxLen << '\n';
    }

    return 0;
}