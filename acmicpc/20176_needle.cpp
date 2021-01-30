// 20176: Needle
// https://www.acmicpc.net/problem/20176
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 120010;
constexpr double PI = 3.14159265358979323846;
using C = complex<double>;

vector<C> top(N), mid(N), bot(N);
vector<int> indexTable;

void FFT(vector<C>& v, bool invert = false) {
    int n = v.size();
    int newN = 1;

    // v.size() needs to be power of two
    while (newN < n)
        newN <<= 1;
    v.resize(newN);

    if (!invert) {
        indexTable.resize(newN);
        memset(indexTable.data(), 0, sizeof(int) * newN);

        // construct index table
        for (int bit = (newN >> 1), j = 1; bit; bit >>= 1, j <<= 1) {
            for (int i = 0; i < newN; ++i) {
                if ((i / j) & 1) {
                    indexTable[i] |= bit;
                }
            }
        }
    }

    // scramble
    FOR(i, 0, newN) {
        if (i < indexTable[i])
            swap(v[i], v[indexTable[i]]);
    }

    int inv = invert ? -1 : 1;
    for (int m = 2; m <= newN; m <<= 1) {
        C e(cos(-2.0 * PI / m * inv), -sin(2.0 * PI / m * inv));
        for (int i = 0; i < newN; i += m) {
            C w = C(1, 0);
            for (int k = 0; k < m / 2; ++k) {
                C even = v[i + k];
                C odd = v[i + k + m / 2] * w;

                v[i + k] = even + odd;
                v[i + k + m / 2] = even - odd;
                w *= e;
            }
        }
    }

    if (invert)
        for (int i = 0; i < newN; ++i)
            v[i] /= newN;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n;
    FOR(i, 0, n) {
        cin >> x;
        top[x + 30000] += 1;
    }
    cin >> n;
    FOR(i, 0, n) {
        cin >> x;
        mid[x + 30000] += 1;
    }
    cin >> n;
    FOR(i, 0, n) {
        cin >> x;
        bot[x + 30000] += 1;
    }

    FFT(top);
    FFT(bot);

    FOR(i, 0, top.size()) {
        top[i] *= bot[i];
    }

    FFT(top, true);
    int ans = 0;
    FOR(i, 0, top.size()) {
        if (i % 2)
            continue;
        int x = (int) (top[i].real() + 0.5);
        ans += mid[i / 2].real() * x;
    }

    cout << ans << '\n';

    return 0;
}