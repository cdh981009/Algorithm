#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e6 + 10;

int ans;
int arr[N];
int n;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
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
        int x;
        cin >> x;
        arr[x]++;
    }

    int cnt = 0;

    FOR(i, 1, N) {
        if (arr[i]) {
            cnt++;
            continue;
        }
        int g = 0;
        for (int j = i + i; j < N; j += i) {
            if (arr[j])
                g = gcd(g, j);
        }

        if (g == i) cnt++;
    }

    cout << cnt - n << '\n';
    return 0;
}