#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;
constexpr int M = 50;

string answers[100];
int sCnt[100];
int sRank[100];
int qCnt[10000];
int qRank[10000];
int value[100];

int p;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ansCnt = 0;

    FOR(i, 0, 10000) {
        qRank[i] = i;
    }
    FOR(i, 0, 100) {
        sRank[i] = i;
    }

    int tc;
    cin >> tc >> p;
    FOR_(caseNum, 1, tc) {
        int ans;
        int cheater = 0;
        //cin >> cheater;

        memset(qCnt, 0, sizeof(int) * 10000);
        memset(sCnt, 0, sizeof(int) * 100);

        // get input
        FOR(i, 0, 100) {
            cin >> answers[i];
            FOR(x, 0, 10000) {
                qCnt[x] += (answers[i][x] == '1');
                sCnt[i] += (answers[i][x] == '1');
            }
        }

        // sort question difficulties
        sort(qRank, qRank + 10000, [](int l, int r) -> bool {
            return qCnt[l] < qCnt[r];
        });

        // cheating 한 사람은 보여지는 실력이
        // 비슷한 주변사람들 보다
        // 어려운 문제는 적게 풀고
        // 쉬운 문제는 많이 풀었을 것이다.
        sort(sRank, sRank + 100, [](int l, int r) -> bool {
            return sCnt[l] < sCnt[r];
        });

        FOR(i, 0, 100) {
            int hard = 0;
            int easy = 0;
            int K = 400;
            FOR(j, 0, K) {
                hard += (answers[i][qRank[j]] == '1');
                easy += (answers[i][qRank[10000 - j - 1]] == '1');
            }
            value[i] = easy - hard;
        } 
        double maxDiff = -1000;
        int suspect = -1;
        // cheat detection
        FOR(i, 0, 100) {
            double diffSum = 0.0;
            int div = 0;
            int curr = sRank[i];
            FOR_(j, -3, 3) {
                if (i + j == i || i + j < 0 || i + j >= 100) {
                    continue;
                }
                div++;
                int neighbour = sRank[i + j];
                diffSum += abs(value[curr] - value[neighbour]);
            }
            diffSum /= div;
            if (diffSum > maxDiff) {
                maxDiff = diffSum;
                suspect = curr;
            }
        }

        ans = suspect + 1;
        cout << "Case #" << caseNum << ": " << ans << '\n';
        if (cheater == ans) {
           ansCnt++;
        }
    }
    //cout << (double)ansCnt / tc << '\n';

    return 0;
}