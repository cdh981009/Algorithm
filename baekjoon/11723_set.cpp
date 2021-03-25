#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m;
    int set = 0;
    while (m--) {
        int x;
        string query; cin >> query;
        if (query == "add") {
            cin >> x;
            set |= (1 << (x-1));
            // cout << "add " << bitset<20>(set) << endl;
        } else if (query == "remove") {
            cin >> x;
            set &= ~(1 << (x-1));
        } else if (query == "check") {
            cin >> x;
            cout << ((set & (1 << (x - 1))) ? 1 : 0) << "\n";
        } else if (query == "toggle") {
            cin >> x;
            set ^= (1 << (x-1));
        } else if (query == "all") {
            set |= (1 << 20) - 1;
        } else if (query == "empty") {
            set = 0;
        }
    }
    return 0;
}