#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301010;
constexpr int X = (1 << 20);

int n, q;
int sn;
int a[N], b[N], c[N];

int seg[X];

int getCarry(int i) {
    i++;
    int ret = 0;
    while (i) {
        ret += c[i];
        i -= (i & -i);
    }
    return ret;
}

void pushCarry(int a, int b, int x) {
    auto uf = [](int i, int x) {
        i++;
        while (i < N) {
            c[i] += x;
            i += (i & -i);
        }
    };
    uf(a, x);
    uf(b + 1, -x);
}

void update(int ind) {
    int x = a[ind] + b[ind];
    ind += sn;
    seg[ind] = (x == 9 ? 1 : 0);
    int sz = 1;
    while (ind > 1) {
        ind >>= 1;
        seg[ind] = (seg[2 * ind] == sz ? seg[2 * ind] + seg[2 * ind + 1] : seg[2 * ind]);
        sz <<= 1;
    }
}

int rangeQuery(int a, int b) {
    a += sn;
    b += sn;
    int sz = 1;
    int left = 0;
    int right = 0;
    while (a <= b) {
        if (a % 2 == 1) {
            if (seg[a] != sz)
                return left + seg[a];
            left += seg[a++];
        }
        if (b % 2 == 0) {
            if (seg[b] != sz)
                right = 0;
            right += seg[b--];
        }
        a /= 2;
        b /= 2;
        sz <<= 1;
    }

    return left + right;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    string str;
    cin >> str;
    FOR(i, 0, n) {
        a[i] = str[n - i - 1] - '0';
    }
    cin >> str;
    FOR(i, 0, n) {
        b[i] = str[n - i - 1] - '0';
    }

    for (sn = 1; sn < n; sn <<= 1)
        ;

    FOR(i, 0, n) {
        update(i);
        if (a[i] + b[i] + getCarry(i) >= 10)
            pushCarry(i + 1, i + 1, 1);
    }

    FOR(i, 0, q) {
        char t;
        int x, d;

        cin >> t >> x >> d;
        x--;
        
        int c = getCarry(x);
        int prv = a[x] + b[x] + c;
        int ans;

        if (t == 'A')
            a[x] = d;
        else
            b[x] = d;
        
        int crr = a[x] + b[x] + c;

        if ((prv < 10 && crr >= 10) || (prv >= 10 && crr < 10)) {
            ans = rangeQuery(x + 1, n - 1) + 1;
            pushCarry(x + 1, x + ans, crr >= 10 ? +1 : -1);
            ans++;
        } else {
            ans = (prv == crr ? 0 : 1);
        }

        update(x);

        cout << ans << '\n';
    }

    return 0;
}