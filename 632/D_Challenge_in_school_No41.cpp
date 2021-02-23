#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<bool> heads;
    FOR(i, 0, n) {
        char c; cin >> c;
        heads.push_back(c == 'R' ? 1 : 0);
    }
    int turns = 0;
    int seconds = 0;
    vector<vector<int>> log;
    FOR(i, 0, n) {
        vector<int> turnsPerSec;
        FOR(j, 0, n - 1) {
            if (heads[j] == 1 && heads[j + 1] == 0) {
                turnsPerSec.push_back(j + 1);
                heads[j] = 0;
                heads[j + 1] = 1;
                turns++;
                j++;
            }
        }
        if (turnsPerSec.empty())
            break;
        log.push_back(turnsPerSec);
        seconds++;
    }

    if (k < seconds || k > turns) {
        cout << -1 << "\n";
    } else {
        int i = 0;
        while (k != seconds) {
            cout << 1 << " " << log[i].back() << "\n";
            log[i].pop_back();
            k--;
            if (log[i].empty()) {
                seconds--;
                i++;
            }
        }
        while (i != log.size()) {
            cout << log[i].size() << " ";
            for (auto j : log[i])
                cout << j << " ";
            cout << "\n"; 
            i++;
        }
    }

    return 0;
}