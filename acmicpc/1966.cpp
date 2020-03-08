#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;
    while (tc--) {
        deque<pair<int, int>> printer;
        int n, ind; cin >> n >> ind;
        FOR(i, 0, n) {
            int pr; cin >> pr;
            printer.push_front({i, pr});
        }
        int cnt = 0;
        while (!printer.empty()) {
            auto doc = printer.back();
            printer.pop_back();
            bool print = true;
            FOR(i, 0, printer.size())
                if (printer[i].second > doc.second)
                    print = false;
            if (print) {
                cnt++;
                if (ind == doc.first) {
                    cout << cnt << "\n";
                    break;
                }
            } else {
                printer.push_front(doc);
            }
        }
    }
    return 0;
}