// 14750: Jerry and Tom
// https://www.acmicpc.net/problem/14750
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
constexpr int K = 5;
constexpr int H = 50;
constexpr int M = 250;

// Dinic: O(EV^2)

struct Point {
    int x;
    int y;
};

bool operator==(const Point& l, const Point& r) {
    return l.x == r.x && l.y == r.y;
}

bool operator!=(const Point& l, const Point& r) {
    return !(l == r);
}

bool operator<(const Point& l, const Point& r) {
    return l.x == r.x ? l.y < r.y : l.x < r.x;
}

Point operator-(const Point& l, const Point& r) {
    return {l.x - r.x, l.y - r.y};
}

Point operator+(const Point& l, const Point& r) {
    return {l.x + r.x, l.y + r.y};
}

bool doesLineCross(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    auto ccw = [](const Point& a, const Point& b, const Point& c) -> int {
        Point l = b - a;
        Point r = c - a;
        long long res = (long long)l.x * r.y - (long long)r.x * l.y;
        return (0 < res) - (res < 0);
    };

    int a = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int b = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    bool cross;
    if (a == 0 && b == 0) {
        // 일직선상에 있다
        vector<Point> aux{p1, p2, p3, p4};
        sort(aux.begin(), aux.end());
        if (aux[0] == p1 || aux[0] == p2)
            cross = (aux[1] != p1 && aux[1] != p2);
        else
            cross = (aux[1] != p3 && aux[1] != p4);
    } else {
        // 교차한다
        cross = (a <= 0 && b <= 0);
    }

    return cross;
}

bool isHoleOnWall(const Point& hole, const Point& w1, const Point& w2) {
    if (w1.x == w2.x) {
        return hole.x == w1.x &&
               min(w1.y, w2.y) <= hole.y &&
               hole.y <= max(w1.y, w2.y);
    } else {
        return hole.y == w1.y &&
               min(w1.x, w2.x) <= hole.x &&
               hole.x <= max(w1.x, w2.x);
    }
}

int flow[M + H + 2][M + H + 2];
int n, k, h, m;
vector<Point> room;
vector<Point> holes;
vector<Point> mice;

const int SRC = M + H;
const int SINK = M + H + 1;

int level[M + H + 2];
int cache[M + H + 2];
vector<int> edge[M + H + 2];

// dinic's algorithm
// generate level graph
bool bfs() {
    memset(level, -1, sizeof(int) * (M + H + 2));

    queue<int> q;
    q.push(SRC);
    level[SRC] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == SINK)
            break;

        for (auto next : edge[curr]) {
            if (level[next] == -1 && flow[curr][next] > 0) {
                level[next] = level[curr] + 1;
                q.push(next);
            }
        }
    }

    return level[SINK] != -1;
}

// augment graph with blocking flow
int dfs(int curr, int cap) {
    if (curr == SINK) {
        return cap;
    }

    for (int i = cache[curr]; i < edge[curr].size(); ++i) {
        cache[curr] = i;
        int next = edge[curr][i];

        if (level[next] == level[curr] + 1 && flow[curr][next] > 0) {
            int c = dfs(next, min(cap, flow[curr][next]));
            if (c > 0) {
                flow[curr][next] -= c;
                flow[next][curr] += c;
                return c;
            }
        }
    }

    return 0;
}

int dinic() {
    int totalFlow = 0;
    while (bfs()) {
        memset(cache, 0, sizeof(int) * (M + H + 2));
        int d;
        while (d = dfs(SRC, INF))
            totalFlow += d;
    }
    return totalFlow;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> h >> m;
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        room.push_back({x, y});
    }
    room.push_back(room[0]);

    FOR(i, 0, h) {
        int x, y;
        cin >> x >> y;
        holes.push_back({x, y});
    }

    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        mice.push_back({x, y});
    }

    auto addEdge = [](int a, int b, int c) {
        flow[a][b] = c;
        edge[a].push_back(b);
        edge[b].push_back(a);
    };

    FOR(i, 0, m) {
        addEdge(SRC, i, 1);

        Point& p1 = mice[i];
        FOR(j, 0, h) {
            Point& p2 = holes[j];

            bool link = true;
            FOR(l, 0, room.size() - 1) {
                Point& p3 = room[l];
                Point& p4 = room[l + 1];

                if (!isHoleOnWall(p2, p3, p4)) {
                    if (doesLineCross(p1, p2, p3, p4)) {
                        link = false;
                        break;
                    }
                }
            }

            if (link) {
                addEdge(i, j + m, 1);
            }
        }
    }

    FOR(i, 0, h) {
        addEdge(i + m, SINK, k);
    }

    cout << (dinic() == m ? "Possible" : "Impossible") << '\n';

    return 0;
}