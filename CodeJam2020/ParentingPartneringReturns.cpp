#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

struct Act {
    pair<int, int> time;
    size_t ind;
    bool operator<(const Act& other) {
        return this->time < other.time;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        int n; cin >> n;
        vector<Act> acts;
        FOR(i, 0, n) {
            int s, e; cin >> s >> e;
            acts.push_back({{s, e}, i});
        }
        sort(acts.begin(), acts.end());
        vector<char> assign(n);
        bool possible = true;
        int cEnd = 0;
        int jEnd = 0;
        FOR(i, 0, n) {
            Act& act = acts[i];
            if (act.time.first >= cEnd) {
                assign[act.ind] = 'C';
                cEnd = act.time.second;
            } else if (act.time.first >= jEnd) {
                assign[act.ind] = 'J';
                jEnd = act.time.second;
            } else {
                possible = false;
                break;
            }
        }

        string ans;
        FOR(i, 0, n) {
            ans.push_back(assign[i]);
        }
        cout << "Case #" << t << ": " << (possible ? ans : "IMPOSSIBLE") << "\n";
    }
    return 0;
}