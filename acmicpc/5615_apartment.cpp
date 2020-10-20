// 5615: 아파트 임대
// https://www.acmicpc.net/problem/5615
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

unsigned int modPow(unsigned int a, unsigned int b, unsigned int m) {
    unsigned long long h = 1ULL;
    unsigned long long x = a;
    while (b > 0) {
        if (b % 2)
            h = (h * x) % m;
        x = (x * x) % m;
        b /= 2;
    }
    return h;
}

bool miller(unsigned int n) {
    const static unsigned int aList[3] = {2, 7, 61};

    for (int i = 0; i < 3; ++i) {
        auto a = aList[i];
        if (a >= n)
            break;

        auto k = n - 1;
        while (true) {
            auto temp = modPow(a, k, n);
            if (temp != 1 && temp != n - 1)
                return false;

            if (temp == n - 1)
                break;

            if (k % 2)
                break;

            k /= 2;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        unsigned int x; cin >> x;
        cnt += miller(x * 2 + 1);
    }

    cout << cnt << "\n";

    return 0;
}