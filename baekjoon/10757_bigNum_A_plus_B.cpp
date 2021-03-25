// 10757: 큰 수 A + B
// https://www.acmicpc.net/problem/10757
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10010;
int A[N];
int B[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b; cin >> a >> b;

    FOR(i, 0, a.size()) {
        A[i] = a[a.size() - 1 - i] - '0';
    }
    FOR(i, 0, b.size()) {
        B[i] = b[b.size() - 1 - i] - '0';
    }

    FOR(i, 0, N - 1) {
        A[i] += B[i];
        A[i+1] += A[i] / 10;
        A[i] %= 10;
    }

    string c;

    bool leadingZero = true;

    FOR(i, 0, N) {
        if (leadingZero && A[N - i - 1] != 0) {
            leadingZero = false;
        }
        if (!leadingZero) {
            c.push_back(A[N - i - 1] + '0');
        }
    }

    cout << c << '\n';
    return 0;
}