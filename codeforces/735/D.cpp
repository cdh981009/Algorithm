#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;
int n, m;
string str;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        str.clear();

        if (n > 1) {
            int a = 0;
            a = n / 2 - 1;

            str.append(a, 'a');
            str.push_back('x');
            if (n % 2)
                str.push_back('z');
            str.append(a + 1, 'a');
        } else {
            str = 'x';
        }

        cout << str << '\n';
    }

    return 0;
}