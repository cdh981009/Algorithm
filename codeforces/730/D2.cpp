#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int k;

int neg(int x) {
    vector<int> aux;
    while (x) {
        int n = x % k;
        int m = n == 0 ? 0 : k - n;

        x /= k;
        aux.push_back(m);
    }

    int ret = 0;
    FOR(i, 0, aux.size()) {
        ret = ret * k + aux[aux.size() - i - 1];
    }

    return ret;
}

int op(int x, int y) {
    vector<int> aux;

    while (x > 0 || y > 0) {
        int n = x % k;
        int m = y % k;
        int a = (n + m) % k;

        x /= k;
        y /= k;
        aux.push_back(a);
    }

    int ret = 0;
    FOR(i, 0, aux.size()) {
        ret = ret * k + aux[aux.size() - i - 1];
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n >> k;

        int y = 0;
        int i = 0;

        while (true) {
            cout << y << '\n';
            cout.flush();

            i++;
            y = (i % 2) ? op(neg(i), i - 1)
                        : op(i, neg(i - 1));

            int x;
            cin >> x;
            if (x == 1) {
                break;
            } else if (x == 0) {
                continue;
            } else {
                return 0;
            }
        }
    }
    return 0;
}