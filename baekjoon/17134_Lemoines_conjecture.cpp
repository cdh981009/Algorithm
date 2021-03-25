// 17134: 르모앙의 추측
// https://www.acmicpc.net/problem/17134
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Fast Fourier Transform의 원리(대충)은 링크 참조
// https://m.blog.naver.com/wjdalsdl1016/221109321310
// 크기 < 2^B;
constexpr int B = 21;
constexpr int N = 1 << B;
constexpr int NUM = 1e6;
constexpr double PI = 3.14159265358979323846;
using C = complex<double>;

int indexTable[N];
bool prime[NUM];

void sieve() {
    FOR(i, 0, NUM)
        prime[i] = true;

    prime[0] = prime[1] = false;

    for (int i = 2; i * i < NUM; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < NUM; j += i) {
                prime[j] = false;
            }
        }
    }
}

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

void FFT(vector<C>& v, bool invert = false) {
    // 재배열
    FOR(i, 0, N) {
        if (i < indexTable[i])
            swap(v[i], v[indexTable[i]]);
    }

    int inv = invert ? -1 : 1;
    for (int m = 2; m <= N; m <<= 1) {
        C e(cos(-2.0 * PI / m * inv), -sin(2.0 * PI / m * inv));
        for (int i = 0; i < N; i += m) {
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
        for (int i = 0; i < N; ++i)
            v[i] /= N;
}

vector<C> vec(N);

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    constructIndexTable();

    sieve();

    FOR(i, 2, NUM) {
        if (prime[i]) {
            if (2 * i <= NUM)
                vec[2 * i] = C(1); // 짝수 세미소수
            vec[i] = C(1); // 홀수 소수
        }
    }
    vec[2] = C(0); // 홀수가 아님

    FFT(vec);
    FOR(i, 0, N) {
        vec[i] = vec[i] * vec[i];
    }
    FFT(vec, true);

    int n; cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        cout << (int)(vec[x].real() + 0.5) / 2 << "\n";
    }

    return 0;
}