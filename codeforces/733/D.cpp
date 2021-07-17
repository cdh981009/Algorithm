#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 20101;
int n;
int wish[N];
int aMat[N];
int bMat[N];
vector<int> aUnmat;
vector<int> bUnmat;

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

        aUnmat.clear();
        bUnmat.clear();
        aUnmat.reserve(n);
        bUnmat.reserve(n);

        int k = 0;
        // greedy
        FOR(i, 0, n) {
            if (bMat[wish[i]] == -1) {
                aMat[i] = wish[i];
                bMat[wish[i]] = i;
                k++;
            } else {
                aUnmat.push_back(i);
            }
        }

        FOR(i, 0, n) {
            if (bMat[i] == -1)
                bUnmat.push_back(i);
        }

        if (k == n - 1) {
            if (aUnmat[0] == bUnmat[0]) {
                // swap
                aMat[aUnmat[0]] = wish[aUnmat[0]];
                aMat[bMat[wish[aUnmat[0]]]] = bUnmat[0];
            } else {
                aMat[aUnmat[0]] = bUnmat[0];
            }
        } else {
            // hall's marriage theorem
            int i = 0;
            while (i < aUnmat.size()) {
                if (aUnmat.size() - i == 3) {
                    // match 3
                    int a[3];
                    int b[3];
                    FOR(j, 0, 3) {
                        a[j] = aUnmat[i + j];
                    }
                    FOR(j, 0, 3) {
                        b[j] = bUnmat[i + j];
                    }

                    constexpr int perm[6][3] = 
                    {
                        {0, 1, 2},
                        {0, 2, 1},
                        {1, 0, 2},
                        {1, 2, 0},
                        {2, 0, 1},
                        {2, 1, 0}
                    };

                    FOR(j, 0, 6) {
                        auto& p = perm[j];
                        bool pos = true;
                        FOR(l, 0, 3) {
                            if (a[l] == b[p[l]]) {
                                pos = false;
                                break;
                            }
                        }
                        if (pos) {
                            FOR(l, 0, 3) {
                                aMat[a[l]] = b[p[l]];
                            }
                        }
                    }
                    break;
                } else {
                    // match 2
                    int a1 = aUnmat[i];
                    int a2 = aUnmat[i + 1];

                    int b1 = bUnmat[i];
                    int b2 = bUnmat[i + 1];

                    if (a1 == b1 || a2 == b2) {
                        aMat[a1] = b2;
                        aMat[a2] = b1;
                    } else {
                        aMat[a1] = b1;
                        aMat[a2] = b2;
                    }
                }
                i += 2;
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