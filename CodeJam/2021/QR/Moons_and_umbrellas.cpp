#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
constexpr int M = 50;

int x, y;
int n;
string str;
// do[i][j] 바로 전 타일이 j일 때 i 번째에서 그림을 그릴 때
// 앞으로 만들 수 있는 최소 cost
int dp[N][3];
bool memoi[N][3];

const int EMPTY = 0, MOON = 1, UMB = 2;

int getDp(int ind, int prev) {
    if (ind == n) {
        return 0;
    }

    int &ret = dp[ind][prev];

    if (memoi[ind][prev])
        return ret;
    memoi[ind][prev] = true;

    ret = INF;

    if (str[ind] == '?') {
        ret = min(ret, 
              getDp(ind + 1, MOON) + 
              (prev == UMB ? y : 0));
        ret = min(ret, 
              getDp(ind + 1, UMB) +
              (prev == MOON ? x : 0));
    } else {
        if (str[ind] == 'C' && prev == UMB)
            ret = getDp(ind + 1, MOON) + y;
        else if (str[ind] == 'J' && prev == MOON)
            ret = getDp(ind + 1, UMB) + x;
        else
            ret = getDp(ind + 1, str[ind] == 'C' ? MOON : UMB);
        
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        memset(memoi, false, sizeof(bool) * N * 3);

        int ans = 0;
        cin >> x >> y;
        cin >> str;
        n = str.size();

        ans = getDp(0, EMPTY);
        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}