#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

using vit = vector<int>::iterator;
vit binarySearch(const vit& begin,const vit& end, int value) {
    auto it = begin;
    for (auto step = distance(begin, end)/ 2; step > 0; step /= 2)
        while ((it + step < end) && (*(it + step) <= value)) it += step;
    if (*it == value)
        return it;
    else
        return end;
}
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    vector<int> nums;
    FOR(i, 0, len) {
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());

    int query; cin >> query;
    FOR(i, 0, query) {
        int v; cin >> v;
        cout << (binarySearch(nums.begin(), nums.end(), v) == nums.end() ? 0 : 1) << "\n";
    }
    return 0;
}