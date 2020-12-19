// 10531: Golf Bot
// https://www.acmicpc.net/problem/10531
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Fast Fourier Transform의 원리(대충)은 링크 참조
// https://m.blog.naver.com/wjdalsdl1016/221109321310

// 구하고자하는 배열의 두배 크기로 resize해야 원하는 convolution을 구할 수 있다.
// 크기 < 2^B;
constexpr int B = 19;
constexpr int N = 1 << B;
constexpr double PI = 3.14159265358979323846;
using C = complex<double>;

vector<int> indexTable;
vector<C> vec(N);

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
    
    int n, m;
    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        vec[x] = 1;
    }
    vec[0] = 1;

    FFT(vec);

    FOR_(i, 0, N) {
        vec[i] = vec[i] * vec[i];
    }

    FFT(vec, true);

    int cnt = 0;
    cin >> m;
    FOR(i, 0, m) {
        int x;
        cin >> x;
        cnt += (vec[x].real() >= 0.5);
    }

    cout << cnt << "\n";

    return 0;
}