#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 201010;
int n;
int wish[N];
int aMat[N];
int bMat[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        memset(aMat, -1, sizeof(int) * n);
        memset(bMat, -1, sizeof(int) * n);

        FOR(i, 0, n) {
            cin >> wish[i];
            wish[i]--;
        }

        // greedy
        int k = 0;
        FOR(i, 0, n) {
            if (bMat[wish[i]] == -1) {
                bMat[wish[i]] = i;
                aMat[i] = wish[i];
                k++;
            }
        }

        int bInd = 0;
        FOR(i, 0, n) {
            if (aMat[i] == -1) {
                while (bInd + 1 < n && bMat[bInd] != -1) {
                    bInd++;
                }
                if (bInd == i) {
                    // swap
                    aMat[bMat[wish[i]]] = i;
                    bMat[i] = bMat[wish[i]];

                    aMat[i] = wish[i];
                    bMat[wish[i]] = i;
                } else {
                    aMat[i] = bInd;
                    bMat[bInd] = i;
                }
                bInd++;
            }
        }

        cout << k << '\n';
        FOR(i, 0, n) {
            cout << aMat[i] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}