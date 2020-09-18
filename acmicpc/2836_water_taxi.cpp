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

    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<bool, int>>> points;
    FOR(i, 0, n) {
        int src, dst; cin >> src >> dst;
        if (src > dst) {
            points.push_back({dst, {false, src}});
            points.push_back({src, {true, dst}});
        }
    }
    sort(points.begin(), points.end());
    int minDst;

    multiset<int> onBoat;
    long long len = m;
    for (auto i = points.begin(); i != points.end(); ++i) {
        bool startingPoint = (i->second).first;
        if (!startingPoint) {
            if (onBoat.empty())
                minDst = i->first;
            onBoat.insert((i->second).second);
        } else {
            onBoat.erase(onBoat.lower_bound(i->first));
            if (onBoat.empty())
                len += 2 * (i->first - minDst);
        }
    }

    cout << len << "\n";
    return 0;
}