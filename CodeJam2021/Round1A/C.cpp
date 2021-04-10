#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)


int n, q;
vector<bool> arr[3];
int score[3];

int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }

    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        int w = 0, z = 0;

        cin >> n >> q;

        string str;
        FOR(i, 0, n) {
            int x;
            cin >> str >> x;
            arr[i].resize(q);
            score[i] = x;
            FOR(j, 0, q) {
                arr[i][j] = (str[j] == 'T');
            }
        }

        vector<int> candids;

        FOR(i, 0, 1 << q) {
            bool valid = true;
            // 이게 정답이라 가정
            FOR(j, 0, n) {
                int cnt = 0;
                FOR(k, 0, q) {
                    if (((i >> (q - k - 1)) & 1) == arr[j][k])
                        cnt++;
                }
                if (cnt != score[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                w++;
                candids.push_back(i);
            }
        }

        int ans = 0;
        FOR(i, 0, 1 << q) {
            // 이게 내 답이라 가정
            int zz = 0;
            FOR(j, 0, candids.size()) {
                FOR(k, 0, q) {
                    if (((i >> (q - k - 1)) & 1) == ((candids[j] >> (q - k - 1)) & 1))
                        zz++;
                }
            }
            if (zz > z) {
                z = zz;
                ans = i;
            }
        }

        cout << "Case #" << caseNum << ": ";
        FOR(i, 0, q) {
            cout << (((ans >> (q - i - 1)) & 1) ? 'T' : 'F');
        }
        cout << ' ';
        
        int g = gcd(z, w);
        cout << z/g << '/' << w/g << '\n';
    }

    return 0;
}