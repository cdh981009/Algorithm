#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, initTemp; cin >> n >> initTemp;
        int tempMin, tempMax = initTemp;
        int time = 0;
        bool possible = true;
        while (n--) {
            int visitTime, cMin, cMax; cin >> visitTime >> cMin >> cMax;
            int delta = visitTime - time;
            time = visitTime;
            tempMax = min(cMax, tempMax + delta);
            tempMin = max(cMin, tempMin - delta);
            if (tempMin > tempMax)
                possible = false;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}