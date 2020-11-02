// 13275: 가장 긴 팰린드롬 부분 문자열
// https://www.acmicpc.net/problem/13275
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5 + 10;
char str[N];
int A[N];

int R;
int p;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    
    FOR(i, 0, n) {
        str[2 * i] = s[i];
        str[2 * i + 1] = '#';
    }

    // Manacher's algorithm
    R = 0; // = p + A[p]; max index that have seen
    p = 0; // index that makes R the biggest

    int maxLen = 0;
    int maxInd = 0;

    FOR(i, 1, 2 * n - 1) {
        int j = 2 * p - i;

        if (i <= R) {
            A[i] = min(R - i, A[j]);
        } // else
        // A[i] = 0;

        int k = A[i] + 1;
        while ((i - k >= 0) && (i + k < 2 * n - 1) && (str[i - k] == str[i + k])) {
            A[i]++;
            k++;
        }

        if (i + A[i] > R) {
            R = i + A[i];
            p = i;
        }

        if (A[i] > maxLen) {
            maxLen = A[i];
            maxInd = i;
        }
    }

    int ans;
    if (str[maxInd] == '#') {
        ans = (maxLen + 1) / 2 * 2;
    } else {
        ans = maxLen / 2 * 2 + 1;
    }
    cout << ans << '\n';

    return 0;
}