// 2419: Beetle
// https://www.acmicpc.net/problem/2419
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301;

int n, k;
multiset<int> bags;
vector<pair<int, int>> jewells;

long long ans;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 0, n) {
        int m, v;
        cin >> m >> v;
        jewells.push_back({v, -m});
    }
    FOR(i, 0, k) {
        int c; cin >> c;
        bags.insert(c);
    }

    sort(jewells.rbegin(), jewells.rend());

    FOR(i, 0, n) {
        auto& p = jewells[i];
        int v = p.first;
        int m = -p.second;
        auto it = bags.lower_bound(m);
        if (it != bags.end()) {
            ans += v;
            bags.erase(it);
        }
    }

    cout << ans << '\n';

    return 0;
}