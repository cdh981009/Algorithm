// 13976: 타일 채우기 2
// https://www.acmicpc.net/problem/13976
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int M = 1e9 + 7;

struct mat2x2 {
    long long x, y, z, w;
};

mat2x2 operator*(const mat2x2& l, const mat2x2& r) {
    return {
            ((l.x * r.x) % M + (l.y * r.z) % M) % M,
            ((l.x * r.y) % M + (l.y * r.w) % M) % M,
            ((l.z * r.x) % M + (l.w * r.z) % M) % M,
            ((l.z * r.y) % M + (l.w * r.w) % M) % M,
    };
}

int cntTile(long long n) {
    n -= 2;

    mat2x2 base = { 4, -1, 1, 0 };
    mat2x2 ret = { 1, 0, 0, 1 };

    while (n) {
        if (n % 2)
            ret = ret * base;
        base = base * base;
        n /= 2;
    }

    return (((ret.x * 11) % M + (ret.y * 3) % M) + M) % M;
}

// f(n) = 4 * f(n - 2) - f(n - 4)
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    if (n % 2) {
        cout << 0 << '\n';
    } else {
        n /= 2;
        if (n == 1) {
            cout << 3 << '\n';
        } else if (n == 2) {
            cout << 11 << '\n';
        } else {
            cout << cntTile(n) << '\n';
        }
    }

    return 0;
}