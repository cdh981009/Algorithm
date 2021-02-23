#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5 + 10;
string s, t;
int n, m;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> s >> t;

    // 뒤에서 부터 x개를 일치시킨 index 최대값 저장
    int j = n - 1;
    for (int i = m - 1; i >= 1; --i) {
        while (s[j] != t[i]) {
            --j;
        }
        // m - i 개 매치함
        arr[m - i] = j;
        --j;
    }

    int ans = 0;

    j = 0;
    for (int i = 0; i < m - 1; ++i) {
        while (s[j] != t[i]) {
            ++j;
        }
        // i + 1 개 match 함
        // m - i - 1개 match한 것은 어디에 있는가
        ans = max(ans, arr[m - i - 1] - j);
        ++j;
    }

    cout << ans << '\n';

    return 0;
}