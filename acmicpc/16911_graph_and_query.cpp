// 16911: 그래프와 쿼리
// https://www.acmicpc.net/problem/16911
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using pii = pair<int, int>;

constexpr int N = 101010;

int rk[N];
int root[N];

struct Edge {
    int u, v, s, e;
} edges[N];

vector<Edge*> events;

pii query[N];
vector<pii> seg[2 * N];

// stack of union find work
vector<pair<pii, bool>> stk; // {{parent, child}, rankChange} = linked child to parent
map<pii, int> mp;

int find(int x) {
    if (root[x] == x)
        return x;
    return find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return 0;

    if (rk[x] < rk[y])
        swap(x, y);

    root[y] = x;

    bool rankChange = false;
    if (rk[x] == rk[y]) {
        ++rk[x];
        rankChange = true;
    }

    stk.push_back({{x, y}, rankChange});

    return 1;
}

void update(const int l, const int r, const int a, const int b, int node, int nodeLeft, int nodeRight) {
    if (l <= nodeLeft && nodeRight <= r) {
        seg[node].push_back({a, b});
        return;
    } else if (r < nodeLeft || nodeRight < l) {
        return;
    }

    int mid = (nodeLeft + nodeRight) / 2;
    update(l, r, a, b, 2 * node, nodeLeft, mid);
    update(l, r, a, b, 2 * node + 1, mid + 1, nodeRight);
}

void revert(int cnt) {
    while (cnt--) {
        auto& p = stk.back();
        int x = p.first.first;
        int y = p.first.second;

        root[y] = y;
        if (p.second)
            rk[x]--;
        
        stk.pop_back();
    }
}

void getAns(int node, int nodeLeft, int nodeRight) {
    int cnt = 0;

    for (auto& p : seg[node]) {
        cnt += unite(p.first, p.second);
    }

    if (nodeLeft == nodeRight) {
        auto& p = query[nodeLeft];
        cout << same(p.first, p.second) << '\n';
    } else {
        int mid = (nodeLeft + nodeRight) / 2;
        getAns(2 * node, nodeLeft, mid);
        getAns(2 * node + 1, mid + 1, nodeRight);
    }

    revert(cnt);
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    FOR_(i, 1, n) {
        root[i] = i;
    }

    int cnt = 0;
    FOR(i, 0, q) {
        int type, u, v; cin >> type >> u >> v;
        if (u < v) swap(u , v);

        if (type == 1) {
            mp[{u, v}] = i;
            edges[i] = {u, v, cnt, INF};
        } else if (type == 2) {
            int ind = mp[{u, v}];
            edges[ind].e = cnt - 1;
            if (edges[ind].s <= edges[ind].e)
                events.push_back(&edges[ind]);
        } else {
            query[cnt] = {u, v};
            cnt++;
        }
    }
    cnt--;

    FOR(i, 0, q) {
        if (edges[i].e == INF) {
            edges[i].e = cnt;
            events.push_back(&edges[i]);
        }
    }

    for (auto p: events) {
        update(p->s, p->e, p->u, p->v, 1, 0, cnt);
    }

    getAns(1, 0, cnt);

    return 0;
}