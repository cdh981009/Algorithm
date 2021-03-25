// 2963: SETNJA
// https://www.acmicpc.net/problem/2963
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
constexpr long long X = 1e10;
// one chunk is 1e10
// 0 ~ 1e10 - 1
long long num[N];
long long aux[N];

void mul(long long n[N], int a) {
    FOR(i, 0, N) {
        n[i] *= a;
    }
    FOR(i, 0, N - 1) {
        n[i + 1] += n[i] / X;
        n[i] %= X;
    }
}

void add(long long n[N], long long a[N]) {
    FOR(i, 0, N) {
        n[i] += a[i];
    }
    FOR(i, 0, N - 1) {
        n[i + 1] += n[i] / X;
        n[i] %= X;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    num[0] = 1;
    aux[0] = 1;

    FOR(i, 0, s.size()) {
        int ind = i;

        switch (s[ind]) {
            case 'R':
                mul(num, 2);
                add(num, aux);
                break;
            case 'L':
                mul(num, 2);
                break;
            case '*':
                mul(num, 5);
                add(num, aux);
                mul(aux, 3);
                break;
        }
    }

    // FOR(i, 0, 10000) {
    //     op(5, 1);
    // }

    bool leadingZ = true;
    string out;

    for (int i = N - 1; i >= 0; --i) {
        if (!leadingZ || num[i] != 0) {
            long long x = X / 10;
            FOR(j, 0, 10) {
                long long n = num[i] / x;
                num[i] %= x;
                if (!leadingZ || n != 0) {
                    leadingZ = false;
                    out.push_back(n + '0');
                }
                x /= 10;
            }
            leadingZ = false;
        }
    }

    cout << out << '\n';
    //cout << out.size() << endl;

    return 0;
}