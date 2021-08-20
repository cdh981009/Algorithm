#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301010;

int n, q;
int a[N], b[N];

// carry 저장, 차이 배열
int tree[N];

int getCarry(int i) {
    i++;
    int ret = 0;
    while (i) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

void pushCarry(int a, int b, int x) {
    auto f = [](int i, int x) {
        i++;
        while (i < N) {
            tree[i] += x;
            i += (i & -i);
        }
    };

    f(a, x);
    f(b + 1, -x);
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

    set<int> notNine;

    FOR(i, 0, n) {
        if (a[i] + b[i] + getCarry(i) >= 10)
            pushCarry(i + 1, i + 1, 1);
        if (a[i] + b[i] != 9)
            notNine.insert(i);
    }
    notNine.insert(n);

    FOR(i, 0, q) {
        char t;
        int x, d;
        cin >> t >> x >> d;
        x--;
        
        int c = getCarry(x);
        int prv = a[x] + b[x] + c;

        if (t == 'A')
            a[x] = d;
        else
            b[x] = d;
        
        int crr = a[x] + b[x] + c;

        int ans;
        if ((prv < 10 && crr >= 10) || (prv >= 10 && crr < 10)) {
            auto it = notNine.upper_bound(x);
            ans = *it - x;
            pushCarry(x + 1, x + ans, crr >= 10 ? +1 : -1);
            ans++;
        } else {
            ans = (prv == crr ? 0 : 1);
        }

        if (a[x] + b[x] == 9)
            notNine.erase(x);
        else if (a[x] + b[x] != 9)
            notNine.insert(x);

        cout << ans << '\n';
    }

    return 0;
}