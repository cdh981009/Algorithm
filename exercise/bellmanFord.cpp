#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int V = 500;
constexpr int ub = INF - 1e8;
int n, m;
vector<pair<int, int>> edges[V + 1];

vector<long long> bellmanFord(int src) {
    vector<long long> upper(n + 1, INF);
    upper[src] = 0;
    bool update;
    for (int iter = 0; iter < n; ++iter) {
        update = false;
        FOR_(i, 1, n) {
            auto& e = edges[i];
            FOR(j, 0, e.size()) {
                int s = i;
                int d = e[j].first;
                int w = e[j].second;
                // 출발점에서 아직 닿지 않은 부분에서 업데이트 되는 것을 방지
                // 따라서 출발점과 다른 컴포넌트에 있는 음수 사이클은 무시 할 수 있게 됨
                if (upper[d] > upper[s] + w && upper[s] + w < ub) {
                    upper[d] = upper[s] + w;
                    update = true;
                }
            }
        }
        if (!update)
            break;
    }
    if (update)
        upper.clear();
    return upper;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    FOR(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    auto ans = bellmanFord(1);
    if (ans.empty()) {
        cout << -1 << "\n";
    } else {
        for (vector<long long>::size_type i = 2; i < ans.size(); ++i)
            cout << (ans[i] <= ub ? ans[i] : -1) << "\n";
    }

    return 0;
}