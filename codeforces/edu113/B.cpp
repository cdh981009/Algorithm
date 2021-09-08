#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 60;

using ll = long long;
using pii = pair<int, int>;

int n;
string arr;
bool won[N];
char ans[N][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> arr;
        bool pos = true;

        memset(won, false, sizeof(bool) * N);

        FOR(i, 0, n) {
            FOR(j, i, n) {
                if (i == j)
                    ans[i][j] = 'X';
                else {
                    if (arr[i] == '1') {
                        ans[i][j] = '=';
                        ans[j][i] = '=';
                    } else {
                        if (won[i]) {
                            ans[i][j] = '-';
                            ans[j][i] = '+';
                            won[j] = true;
                        } else {
                            if (arr[j] == '2') {
                                ans[i][j] = '+';
                                ans[j][i] = '-';
                                won[i] = true;
                            } else {
                                ans[i][j] = '=';
                                ans[j][i] = '=';
                            }
                        }
                    }
                }
            }
        }

        FOR(i, 0, n) {
            if (arr[i] == '2' && !won[i]) {
                pos = false;
                break;
            }
        }

        if (pos) {
            cout << "YES\n";
            FOR(i, 0, n) {
                FOR(j, 0, n) {
                    char o;
                    o = ans[i][j];
                    cout << o;
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}