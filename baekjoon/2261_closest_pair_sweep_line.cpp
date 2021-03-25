#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
//TODO: SWEEP LINE ALGORITHM SOLUTION!!
// O(nlogn) solution

int distance(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return (lhs.first - rhs.first) * (lhs.first - rhs.first) + (lhs.second - rhs.second) * (lhs.second - rhs.second); 
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> pos(n);
    FOR(i, 0, n) {
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
    }
    sort(pos.begin(), pos.end()); // order by x coordinate
    int minD = INF;
    auto cmpY = [](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool 
        {
            return lhs.second != rhs.second ? lhs.second < rhs.second : lhs.first < rhs.first;
        };
    set<pair<int, int>, decltype(cmpY)> candids(cmpY);
    size_t indX = 0;
    FOR(i, 0, n) {
        auto p1 = pos[i];
        while (indX < i &&
                ((p1.first - pos[indX].first) * (p1.first - pos[indX].first) >= minD)) {
            candids.erase(pos[indX++]);
        }
        auto btm = candids.lower_bound({0, p1.second - (int) floor(sqrt(minD))});
        auto top = candids.lower_bound({0, p1.second + (int) ceil(sqrt(minD))});
        //cout << distance(candids.begin(), btm) << endl; 
        //cout << distance(candids.begin(), top) << endl;
        for (auto it = btm; it != top; ++it) {
            minD = min(minD, distance(p1, *it));
            //cout << "asd" << endl;
        }
        candids.insert(p1);
    }

    cout << minD << endl;
    return 0;
}