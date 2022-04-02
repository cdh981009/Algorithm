#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 123;

using ll = __int128;

ll dp[N][N];

int n, q;

ll gcd(ll a, ll b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }

    return a;
}

bool arr[N][3];
int score[3];
int type[N];

ostream& operator<<(ostream& o, ll x) {
    string str;
    if (x == 0) {
        o << 0;
        return o;
    }

    while (x) {
        str += ((int)(x % 10) + '0');
        x /= 10;
    }

    reverse(str.begin(), str.end());
    o << str;
    return o;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    FOR(i, 0, N) {
        dp[i][0] = dp[i][i] = 1;
    }
    FOR(i, 1, N) {
        FOR(j, 1, i) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        FOR(i, 0, q) {
            arr[i][0] = arr[i][1] = arr[i][2] = 0;
        }
        cin >> n >> q;

        FOR(i, 0, n) {
            string str;
            cin >> str >> score[i];
            if (i == 0)
                score[2] = score[1] = score[0];
            FOR(j, 0, q) {
                if (i == 0 && str[j] == 'T')
                    arr[j][0] = arr[j][1] = arr[j][2] = 1;
                else
                    arr[j][i] = str[j] == 'T';
            }
        }

        ll q0, q1, q2, q3;
        q0 = q1 = q2 = q3 = 0;

        FOR(i, 0, q) {
            auto& x = arr[i];
            if (x[0] == x[1]) {
                if (x[1] == x[2]) {
                    q0++;
                    type[i] = 0;
                } else {
                    q1++;
                    type[i] = 1;
                }
            } else {
                if (x[1] == x[2]) {
                    q3++;
                    type[i] = 3;
                } else {
                    q2++;
                    type[i] = 2;
                }
            }
        }

        auto valid = [&](int t0, int t1, int t2, int t3) {
            bool x = (t0 + t1 - t2 - t3 + q2 + q3) == score[1];
            bool y = (t0 - t1 + t2 - t3 + q1 + q3) == score[2];

            return x && y;
        };

        ll A, B, C, D;
        A = B = C = D = 0;
        ll Q = 0;
        ll P = 0;

        FOR_(i0, 0, q0)
        FOR_(i1, 0, q1)
        FOR_(i2, 0, q2) {
            int i3 = score[0] - i0 - i1 - i2;
            if (i3 < 0 || i3 > q3)
                continue;

            if (valid(i0, i1, i2, i3)) {
                ll q = dp[q0][i0] * dp[q1][i1] * dp[q2][i2] * dp[q3][i3];
                Q += q;

                A += i0 * q;
                B += i1 * q;
                C += i2 * q;
                D += i3 * q;
            }
        }

        bool a, b, c, d;
        a = b = c = d = false;
        if (A * 2 >= Q * q0) {
            a = true;
            P += A;
        } else {
            P += Q * q0 - A;
        }
        if (B * 2 >= Q * q1) {
            b = true;
            P += B;
        } else {
            P += Q * q1 - B;
        }
        if (C * 2 >= Q * q2) {
            c = true;
            P += C;
        } else {
            P += Q * q2 - C;
        }
        if (D * 2 >= Q * q3) {
            d = true;
            P += D;
        } else {
            P += Q * q3 - D;
        }

        cout << "Case #" << caseNum << ": ";
        FOR(i, 0, q) {
            if (type[i] == 0) {
                if (a)
                    cout << (arr[i][0] ? 'T' : 'F');
                else
                    cout << (arr[i][0] ? 'F' : 'T');
            }
            if (type[i] == 1) {
                if (b)
                    cout << (arr[i][0] ? 'T' : 'F');
                else
                    cout << (arr[i][0] ? 'F' : 'T');
            }
            if (type[i] == 2) {
                if (c)
                    cout << (arr[i][0] ? 'T' : 'F');
                else
                    cout << (arr[i][0] ? 'F' : 'T');
            }
            if (type[i] == 3) {
                if (d)
                    cout << (arr[i][0] ? 'T' : 'F');
                else
                    cout << (arr[i][0] ? 'F' : 'T');
            }
        }
        cout << ' ';

        ll g = gcd(P, Q);
        cout << (P / g) << '/' << (Q / g) << '\n';
    }

    return 0;
}