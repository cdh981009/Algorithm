#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

void solve() {
    string str;
    cin >> str;

    FOR_(i, 1, 999) {
        int a = i;

        string x;
        while (x.size() < str.size()) {
            string y = to_string(a);
            x += y;
            a++;
        }

        if (x == str) {
            cout << i << ' ' << a - 1 << '\n';
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}