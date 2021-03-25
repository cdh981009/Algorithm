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

    int n;
    cin >> n;
    vector<pair<int, int>> lines;
    FOR(i, 0, n) {
        int s, e; cin >> s >> e;
        if (e < s) swap(s, e);
        lines.push_back({s, e});
    }
    sort(lines.begin(), lines.end());
    int prevEnd;
    int len = 0;
    for (auto i = lines.begin(); i != lines.end(); ++i) {
        if (i == lines.begin() || i->first > prevEnd) {
            prevEnd = i->second;
            len += i->second - i->first;
        } else {
            len += max(0, i->second - prevEnd);
            prevEnd = max(prevEnd, i->second);
        }
    }

    cout << len << "\n";
    return 0;
}