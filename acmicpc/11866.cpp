#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    deque<int> table;
    vector<int> log; 
    FOR(i, 0, n)
        table.push_front(i + 1);
    int cnt = 0;
    while (!table.empty()) {
        cnt++;
        if (cnt == k) {
            cnt = 0;
            log.push_back(table.back());
            table.pop_back();
        } else {
            table.push_front(table.back());
            table.pop_back();
        }
    }

    cout << "<";
    FOR(i, 0, log.size()) {
        cout << log[i] << ((i == log.size() - 1) ? "" : ", ");
    } 
    cout << ">\n";
    return 0;
}