// 1067: 이동
// https://www.acmicpc.net/problem/1067
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Fast Fourier Transform의 원리(대충)은 링크 참조
// https://m.blog.naver.com/wjdalsdl1016/221109321310
// 크기 < 2^B;
constexpr int B = 18;
constexpr int N = 1 << B;
constexpr double PI = 3.14159265358979323846;
using C = complex<double>;

int indexTable[N];

// 계산의 편의를 위해서 홀수항과 짝수항을 재귀적으로 모은다
// 바뀐 인덱스를 저장하는 테이블
void constructIndexTable() {
    // construct index table
    for (int bit = 1 << (B - 1), j = 1; bit; bit >>= 1, j <<= 1) {
        for (int i = 0; i < N; ++i) {
            if ((i / j) & 1) {
                indexTable[i] |= bit;
            }
        }
    }
}

vector<C> aux(N);
void FFT(vector<C>& v, bool invert = false) {
    // 재배열
    FOR(i, 0, N)
    aux[i] = v[indexTable[i]];

    int inv = invert ? -1 : 1;
    for (int m = 2; m <= N; m <<= 1) {
        C e(cos(-2.0 * PI / m * inv), -sin(2.0 * PI / m * inv));
        for (int i = 0; i < N; i += m) {
            C w = C(1, 0);
            for (int k = 0; k < m / 2; ++k) {
                C even = aux[i + k];
                C odd = aux[i + k + m / 2] * w;

                v[i + k] = even + odd;
                v[i + k + m / 2] = even - odd;
                w *= e;
            }
        }

        swap(aux, v);
    }

    swap(aux, v);
    if (invert)
        for (int i = 0; i < N; ++i)
            v[i] /= N;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    constructIndexTable();

    vector<C> vx(N), vy(N);

    int n;
    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        vx[i] = vx[i + n] = x;
    }

    FOR(i, 0, n) {
        int x;
        cin >> x;
        vy[n - i - 1] = x;
    }

    FFT(vx);
    FFT(vy);

    FOR_(i, 0, N) {
        vx[i] = vx[i] * vy[i];
    }

    FFT(vx, true);

    int ans = 0;
    FOR(i, 0, 2 * n) {
        ans = max(ans, (int)round(vx[i].real()));
    }

    cout << ans << endl;

    return 0;
}