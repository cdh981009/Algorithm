// 12429: 생존자 (Small)
// https://www.acmicpc.net/problem/12429
#include <bits/stdc++.h>

using namespace std;

#define INF (1e7 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10;

int n;
int ans;
int p[N], s[N];

bool picked[N];

void pick(int t) {
    ans = max(ans, t);

    FOR(i, 0, n) {
        if (!picked[i] && p[i] >= t) {
            picked[i] = true;
            pick(t + s[i]);
            picked[i] = false;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    int caseNum = 1;
    while (tc--) {
        memset(picked, 0, sizeof(bool) * N);
        ans = 0;

        cin >> n;
        FOR(i, 0, n) {
            cin >> p[i] >> s[i];
        }

        pick(0);

        cout << "Case #" << caseNum << ": " << ans << '\n';
        caseNum++;
    }
    

    return 0;
}