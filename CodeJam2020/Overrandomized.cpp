#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        int u; cin >> u;
        vector<bool> appear(26, false);
        vector<int> leadingDigit(26, 0);
        for (int i = 0; i < 1e4; ++i) {
            long long q; cin >> q;
            string r; cin >> r;
            leadingDigit[r[0] - 'A']++;
            for (int j = 0; j < r.size(); ++j)
                appear[r[j] - 'A'] = true;
        }
        vector<pair<int, char>> count;
        for (int i = 0; i < 26; ++i)
            if (appear[i])
                count.push_back({leadingDigit[i], i + 'A'});
        sort(count.begin(), count.end());
        string ans;
        ans.push_back(count[0].second);
        for (int i = 1; i < 10; ++ i) {
            ans.push_back(count[10 - i].second);
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}