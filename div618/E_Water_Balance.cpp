#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define pil pair<int, long>
#define x first
#define y second

bool ccw(const pil& p1, const pil& p2, const pil& p3) {
    pil v1 = {p2.x - p1.x, p2.y - p1.y};
    pil v2 = {p3.x - p2.x, p3.y - p2.y};
    return (long long) v1.x * v2.y > (long long) v2.x * v1.y;
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    vector<int> water;
    vector<long long> prefix;
    while (len--) {
        int x; cin >> x;
        water.push_back(x);
        prefix.push_back((prefix.empty() ? 0LL : prefix.back()) + x);
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
    
    vector<double> answer;
    FOR(i, 1, convexHull.size()) {
        int left = convexHull[i - 1];
        int right = convexHull[i];
        
    }

    for (auto d : answer) {
        cout << setprecision(10) << d << " ";
    }
    cout << "\n";
    
    return 0;
}