// 11012: egg
// https://www.acmicpc.net/problem/11012
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 18);
int n;
// 1-based array
int segTree[N];

enum Type {
    START = 0,
    POINT = 1,
    END = 2
};

struct Event {
    Type t;
    int x;
    int y1;
    int y2;
};

void init(int sz) {
    for (n = 1; n < sz; n <<= 1)
        ;
}

void update(int value, int a, int b, int l, int r, int n) {
    if (b < l || a > r)
        return;

    if (l == r) {
        segTree[n] += value;
        return;
    }

    if (a <= l && r <= b) {
        // 현재 노드가 의미하는 범위를 완전히 덮는 경우
        segTree[n] += value;
    } else {
        int m = (l + r) / 2;
        update(value, a, b, l, m, n * 2);
        update(value, a, b, m + 1, r, n * 2 + 1);
    }

    return;
}

void update(const Event& e) {
    update(e.t == START ? +1 : -1, e.y1, e.y2, 0, n - 1, 1);
}

int query(int y) {
    int res = 0;

    int node = 1;
    int l = 0;
    int r = n - 1;

    while (true) {
        res += segTree[node];

        if (l == r)
            break;

        int m = (l + r) / 2;
        if (y <= m) {
            r = m;
            node *= 2;
        } else {
            l = m + 1;
            node = node * 2 + 1;
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init(1e5 + 1);

    int tc;
    cin >> tc;
    while (tc--) {
        memset(segTree, 0, sizeof(int) * N);

        int n, m;
        cin >> n >> m;

        vector<Event> events;
        events.reserve(n + 2 * m);

        FOR(i, 0, n) {
            int x, y; cin >> x >> y;
            events.push_back({POINT, x, y});
        }
        FOR(i, 0, m) {
            int x1, x2, y1, y2;
            cin >> x1 >> x2 >> y1 >> y2;
            events.push_back({START, x1, y1, y2});
            events.push_back({END, x2, y1, y2});
        }
    
        sort(events.begin(), events.end(), [](const Event& l, const Event& r) {
            if (l.x == r.x) {
                return l.t < r.t;
            } else {
                return l.x < r.x;
            }
        });

        int egg = 0;
        for (auto& e : events) {
            if (e.t == POINT)
                egg += query(e.y1);
            else
                update(e);
        }

        cout << egg<< "\n";
    }

    return 0;
}