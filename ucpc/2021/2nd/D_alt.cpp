#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301010;
constexpr int M = 1e6 + 10;

using ll = long long;
using pii = pair<int, int>;

int n;

struct Node {
    int x, y, v;
    bool operator<(const Node& o) {
        return this->y < o.y;
    }
};

vector<Node> nodes;

int solve() {
    vector<int> scores(M, 0);
    vector<int> xs;
    for (auto& nd : nodes) {
        if (scores[nd.x] == 0)
            xs.push_back(nd.x);
        scores[nd.x] += nd.v;
    }

    sort(xs.begin(), xs.end(), [&](int l, int r) {
        return scores[l] > scores[r];
    });

    int ans = 0;
    if (xs.size() >= 3)
        FOR(i, 0, 3)
            ans += scores[xs[i]];
    
    sort(nodes.begin(), nodes.end());
    for (int i = 0; i < n;) {
        int e = i;
        while (e < n && nodes[i].y == nodes[e].y) e++;
        int curr = 0;
        for (int j = i; j < e; j++) {
            scores[nodes[j].x] -= nodes[j].v;
            curr += nodes[j].v;
        }

        int len = e - i + 2;
        int m1, m2;
        m1 = m2 = 0;
        FOR(j, 0, min(len, (int)xs.size())) {
            int x = scores[xs[j]];
            if (x >= m1) {
                m2 = m1;
                m1 = x;
            } else if (x >= m2) {
                m2 = x;
            }
        }

        ans = max(ans, m1 + m2 + curr);
        for (int j = i; j < e; j++)
            scores[nodes[j].x] += nodes[j].v;
        i = e;
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        Node nd;
        cin >> nd.x >> nd.y >> nd.v;
        nodes.push_back(nd);
    }

    int ans = solve();
    for (auto& nd : nodes) {
        swap(nd.x, nd.y);
    }
    ans = max(ans, solve());
    cout << ans << '\n';

    return 0;
}