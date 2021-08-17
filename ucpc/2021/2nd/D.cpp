#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301010;
constexpr int X = (1 << 20);

using ll = long long;
using pii = pair<int, int>;

int n;

struct Node {
    int x, y, v;
} nodes[N];
int xs[N];
int ys[N];
int ux, uy;

int xscore[N];
int yscore[N];
vector<Node*> xnodes[N];
vector<Node*> ynodes[N];

int sn;
pii seg[X];

void updateNode(int i) {
    int aux[4] = {
            seg[2 * i].first,     seg[2 * i].second,
            seg[2 * i + 1].first, seg[2 * i + 1].second};
    sort(aux, aux + 4);
    seg[i] = {aux[3], aux[2]};
}

void init(int* arr, int size) {
    for (sn = 1; sn < size; sn <<= 1)
        ;
    FOR(i, 0, sn) {
        seg[i + sn].second = 0;
        seg[i + sn].first = (i < size ? arr[i] : 0);
    }
    for (int i = sn - 1; i >= 1; --i) {
        updateNode(i);        
    }
}

void update(int a, int x) {
    a += sn;
    seg[a].first += x;
    while (a > 1) {
        a >>= 1;
        updateNode(a);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        int x, y, v;
        cin >> x >> y >> v;
        xs[i] = x;
        ys[i] = y;
        nodes[i] = {x, y, v};
    }

    sort(xs, xs + n);
    ux = unique(xs, xs + n) - xs;

    sort(ys, ys + n);
    uy = unique(ys, ys + n) - ys;

    FOR(i, 0, n) {
        auto& node = nodes[i];
        node.x = lower_bound(xs, xs + ux, node.x) - xs;
        node.y = lower_bound(ys, ys + uy, node.y) - ys;

        xscore[node.x] += node.v;
        yscore[node.y] += node.v;

        xnodes[node.x].push_back(&node);
        ynodes[node.y].push_back(&node);
    }

    auto big3 = [](int* arr, int size) {
        int m1, m2, m3;
        m1 = m2 = m3 = 0;
        FOR(i, 0, size) {
            int x = arr[i];
            if (x >= m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x >= m2) {
                m3 = m2;
                m2 = x;
            } else if (x >= m3) {
                m3 = x;
            }
        }
        return m1 + m2 + m3;
    };

    int ans = 0;
    ans = max(ans, big3(xscore, ux));
    ans = max(ans, big3(yscore, uy));

    init(xscore, ux);
    FOR(i, 0, uy) {
        int y = yscore[i];
        int x = 0;

        for (auto node : ynodes[i]) {
            update(node->x, -(node->v));
        }

        x = seg[1].first + seg[1].second;

        for (auto node : ynodes[i]) {
            update(node->x, node->v);
        }

        ans = max(ans, y + x);
    }

    init(yscore, uy);
    FOR(i, 0, ux) {
        int x = xscore[i];
        int y = 0;

        for (auto node : xnodes[i]) {
            update(node->y, -(node->v));
        }

        y = seg[1].first + seg[1].second;

        for (auto node : xnodes[i]) {
            update(node->y, node->v);
        }

        ans = max(ans, y + x);
    }

    cout << ans << '\n';

    return 0;
}