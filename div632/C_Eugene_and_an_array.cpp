#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<long long, int>> pre;
    long long ans = 0;
    FOR(i, 0, n) {
        int x; cin >> x;
        pre.push_back({(pre.empty() ? 0LL : pre.back().first) + x, i});
    }
    vector<pair<long long, int>> preSort(pre);
    sort(preSort.begin(), preSort.end());
    int lub = n;
    for (int i = n - 1; i >= 0; --i) {
        pair<long long, int> val = {(i == 0 ? 0LL : pre[i - 1].first), i};
        auto it = lower_bound(preSort.begin(), preSort.end(), val);
        if (it != preSort.end() && it->first == val.first && it->second < lub) {
            ans += it->second - i;
            lub = it->second;
        } else {
            ans += lub - i;
        }
    }
    cout << ans << "\n";

    return 0;
}