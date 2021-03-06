#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define ull unsigned long long
#define pil pair<int, ull>
#define x first
#define y second

bool ccw(const pil& p1, const pil& p2, const pil& p3) {
    pil v1 = {p2.x - p1.x, (ull)p2.y - p1.y};
    pil v2 = {p3.x - p2.x, (ull)p3.y - p2.y};
    return (ull) v1.x * v2.y > (ull) v2.x * v1.y;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    vector<ull> prefix;
    prefix.push_back(0);
    while (len--) {
        int x; cin >> x;
        prefix.push_back(prefix.back() + x);
    }

    vector<int> convexHull; // index of convex hull points
    convexHull.push_back(0);
    convexHull.push_back(1);

    int next = 2;
    while (next < prefix.size()) {
        if (convexHull.size() > 1) {
            int middle = convexHull.back(); convexHull.pop_back();
            int first = convexHull.back();

            if (!ccw({first, prefix[first]},
                    {middle, prefix[middle]}, 
                    {next, prefix[next]})) {
                continue;
            }

            convexHull.push_back(middle);
        }
        convexHull.push_back(next);
        next++;
    }
    
    vector<double> ans(prefix.size());

    FOR(i, 1, convexHull.size()) {
      int left = convexHull[i - 1];
      int right = convexHull[i];
      ull sum = prefix[right] - prefix[left];
      int size = right - left;
      FOR_(j, left + 1, right) {
        cout << fixed << setprecision(10) << (double) sum / size << "\n";
      }
    }
    
    return 0;
}
