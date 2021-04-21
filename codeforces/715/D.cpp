#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;

int n;
string str[3];
string ans;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> str[0] >> str[1] >> str[2];
        ans.clear();

        bool tZero;
        bool sZero[3];

        int zCnt = 0;
        int sCnt[3];

        FOR(i, 0, 3) {
            sCnt[i] = 0;
            FOR(j, 0, 2 * n) {
                if (str[i][j] == '0') {
                    sCnt[i]++;
                }
            }
            sZero[i] = (sCnt[i] >= n);
            zCnt += sZero[i];
        }

        tZero = zCnt >= 2;
        int a, b;
        if (sZero[0] == tZero) {
            a = 0;
            b = (sZero[1] == tZero) ? 1 : 2;
        } else {
            a = 1;
            b = 2;
        }

        if (tZero ? sCnt[a] < sCnt[b] : sCnt[a] > sCnt[b])
            swap(a, b);
        
        // merge a and b
        int j = 0;
        FOR(i, 0, 2 * n) {
            while (j < 2 * n && (str[b][j] == '0') != tZero) {
                ans.push_back(str[b][j]);
                j++;
            }
            ans.push_back(str[a][i]);
            if ((str[a][i] == '0') == tZero) {
                j++;
            }
        }

        while (j < 2 * n) {
            if ((str[b][j] == '0') != tZero)
                ans.push_back(str[b][j]);
            j++;
        }

        while (ans.size() < 3 * n) {
            ans.push_back('0');
        }
        cout << ans << '\n';
    }

    return 0;
}