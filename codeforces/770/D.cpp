#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
int n;

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        int x, y, mx, my, res;
        mx = -1;
        FOR_(i, 3, n) {
            cout << "? 1 2 " << i << '\n';
            cout.flush();
            cin >> res;
            if (res == -1) return 0;
            if (mx < res) {
                mx = res;
                x = i;
            }
        }

        my = mx;
        y = 1;
        FOR_(i, 2, n) {
            if (i == x) continue;
            cout << "? 1 " << i << ' ' << x << '\n';
            cout.flush();
            cin >> res;
            if (res == -1) return 0;
            if (my < res) {
                my = res;
                y = i;
            }
        }

        if (y == 1) {
            int z;
            if (n == x) z = n - 1;
            else z = n;
            cout << "? 1 " << z << ' ' << x << '\n';
            cout.flush();
            cin >> res;

            cout << "? 2 " << z << ' ' << x << '\n';
            cout.flush();
            int w;
            cin >> w;
            if (max(w, res) < mx) {
                x = 1, y = 2;
            } else if (w > res) y = 2;
        }


        cout << "! " << x << ' ' << y << '\n';
        cout.flush();
    }
    return 0;
}