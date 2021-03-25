#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prevInd(n);
    vector<pair<int, int>> lis;

    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = x;

        auto it = lower_bound(lis.begin(), lis.end(), make_pair(x, 0));
        int ind = it - lis.begin();

        if (ind == lis.size())
            lis.push_back({x, i});
        else
            *it = {x, i};
        prevInd[i] = (ind == 0 ? -1 : lis[ind - 1].second);
    }

    cout << lis.size() << "\n";
    vector<int> log;
    int curr = lis.back().second;
    while (curr != -1) {
        log.push_back(curr);
        curr = prevInd[curr];
    }
    for (auto i = log.rbegin(); i != log.rend(); ++i)
        cout << arr[*i] << " ";
    cout << "\n";

    return 0;
}