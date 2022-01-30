#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;

int ans[N];
int arr[N];
int n;
int sn;

int seg[4 * N];

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int query(int a, int b) {
    a += sn;
    b += sn;
    int g = 0;
    while (a <= b) {
        if (a % 2 == 1) // odd
            g = gcd(g, seg[a++]);
        if (b % 2 == 0) // even
            g = gcd(g, seg[b--]);
        a /= 2;
        b /= 2;
    }
    return g;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
    
    for (sn = 1; sn < n; sn <<= 1)
        ;
    
    for (int i = 0; i < sn; ++i) {
        seg[i + sn] = (i < n ? arr[i] : 0);
    }
    for (int i = sn - 1; i >= 1; --i) {
        seg[i] = gcd(seg[2 * i], seg[2 * i + 1]);
    }

    int cnt = 0;
    int a = 0;

    FOR(i, 0, n) {
        if (arr[i] == 1) {
            cnt = i + 1;
            a++;
        } else {
            int ind = i;

            for (int step = n; step >= 1; step /= 2) {
                while (true) {
                    int x = ind - step;
                    int d = query(x, i);
                    if (x >= cnt && d >= i - x + 1)
                        ind = x;
                    else
                        break;
                }
            }

            if (query(ind, i) == i - ind + 1) {
                cnt = i + 1;
                a++;
            }
        }

        ans[i] = a;
    }

    FOR(i, 0, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}