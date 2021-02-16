// 2963: SETNJA
// https://www.acmicpc.net/problem/2963
#include <bits/stdc++.h>

using namespace std;

#define INF 1e6
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e4;
// one chunk is 1e4
// 0 ~ 9999
int num[N];

void op(int m, int a) {
    FOR(i, 0, N) {
        num[i] *= m;
    }
    num[0] += a;
    int i = 0;
    FOR(i, 0, N - 1) {
        num[i + 1] += num[i] / N;
        num[i] %= N;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    num[0] = 1;

    FOR(i, 0, s.size()) {
        int ind = i;

        switch (s[ind]) {
            case 'R':
                op(2, 1);
                break;
            case 'L':
                op(2, 0);
                break;
            case '*':
                op(5, 1);
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
            int x = 1000;
            FOR(j, 0, 4) {
                int n = num[i] / x;
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