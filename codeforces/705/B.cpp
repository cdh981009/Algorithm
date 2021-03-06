#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5001;

int h, m;
string s;
int a, b, c, d;

bool symNum(int x) {
    return x == 0 ||
           x == 1 ||
           x == 2 ||
           x == 5 ||
           x == 8;
}

int flip(int x, int y) {
    if (x == 2)
        x = 5;
    else if (x == 5)
        x = 2;

    if (y == 2)
        y = 5;
    else if (y == 5)
        y = 2;

    return 10 * y + x;
}

bool sym() {
    if (symNum(a) &&
            symNum(b) &&
            symNum(c) &&
            symNum(d) &&
            flip(c, d) < h &&
            flip(a, b) < m) {
        return true;
    }
    return false;
}

void nxt() {
    d++;
    if (d >= 10) {
        d = 0;
        c++;
    }

    if (10 * c + d >= m) {
        c = d = 0;
        b++;
        if (b >= 10) {
            b = 0;
            a++;
        }
    }

    if (10 * a + b >= h) {
        a = b = 0;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> h >> m;
        cin >> s;
        a = s[0] - '0';
        b = s[1] - '0';
        c = s[3] - '0';
        d = s[4] - '0';

        while (!sym()) {
            //cout << a << b << ':' << c << d << '\n';
            nxt();
        }

        cout << a << b << ':' << c << d << '\n';
    }
    return 0;
}