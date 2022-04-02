#include <bits/stdc++.h>
#include <random>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Cheating Detection problem text case generator

constexpr int N = 1e4;
constexpr int M = 50;

double q[10000];
double s[100];
int cht[100];

int p;

double sigmoid(double v) {
    return (1.0 / (1.0 + exp(-v)));
}

int main() {
    //freopen("input.txt", "r", stdin);
    auto f = freopen("input.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 50;
    cout << tc << '\n'
         << 0 << '\n';

    mt19937 mersenne(time(0));
    uniform_int_distribution<int> ch(0, 99);
    uniform_int_distribution<int> die(0, 1);
    uniform_real_distribution<double> sol(0.0, 1.0);
    uniform_real_distribution<double> skill(-3.0, 3.0);

    FOR(cn, 0, tc) {
        int cheater = ch(mersenne);
        cht[cn] = cheater + 1;

        FOR(i, 0, 10000) {
            q[i] = skill(mersenne);
        }
        FOR(i, 0, 100) {
            s[i] = skill(mersenne);
        }

        FOR(i, 0, 100) {
            FOR(j, 0, 10000) {
                if (i == cheater) {
                    if (die(mersenne) == 1) {
                        cout << 1;
                    } else {
                        if (sol(mersenne) <= sigmoid(s[i] - q[j])) {
                            cout << 1;
                        } else {
                            cout << 0;
                        }
                    }
                } else {
                    if (sol(mersenne) <= sigmoid(s[i] - q[j])) {
                        cout << 1;
                    } else {
                        cout << 0;
                    }
                }
            }
            cout << '\n';
        }
    }

    ofstream fo("ans.txt");

    FOR(i, 0, tc) {
        fo << cht[i] << '\n';
    }

    return 0;
}