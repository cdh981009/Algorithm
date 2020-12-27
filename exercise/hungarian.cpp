// 14216: 할 일 정하기
// https://www.acmicpc.net/problem/14216
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// hungarian algorithm
// O(V^3)
// https://skkuassa.tistory.com/186

// minimum assignment problem
// i.e.  bipartite perfect matching with minumum cost

// maximum assignment problem을 구현하고 싶다면:
// feasible labeling이 cost[x][y] <= l[x] + [y]이 되므로 (min은 l[x] + l[y] <= cost[x][y])
// 1. slack을 cost[x][y] - l[x] - l[y] 가 아닌 l[x] + l[y] - cost[x][y]로 바꾸고
// 2. label update시 S 집합은 +a에서 -a로, T 집합은 -a에서 +a로 바꾼다

constexpr int N = 500;

int n;
int cost[N][N];

int lx[N], ly[N];

// matching info: if -1, not matching (free)
int y2x[N];
int x2y[N];

// sets
vector<int> S;
bool T[N];

int slack[N];   // min(cost[x][y] - l[x] - l[y]) (for all x in S)
int slack2X[N]; // which x makes slack minimum

int ans;

int matchingCnt = 0;

// init labels of xs to their min cost
// O(V^2)
void initLabels() {
    memset(x2y, -1, sizeof(int) * n);
    memset(y2x, -1, sizeof(int) * n);

    FOR(x, 0, n) {
        int index = 0;
        lx[x] = INF;

        // l[y] = 0, l[x] = min(cost[x][y])
        // fits l[x] + l[y] <= cost[x][y] (for all x, y)
        FOR(y, 0, n) {
            if (lx[x] > cost[x][y]) {
                lx[x] = cost[x][y];
                index = y;
            }
        }

        // initial matching
        if (y2x[index] == -1) {
            y2x[index] = x;
            x2y[x] = index;
            matchingCnt++;
        }
    }
}

// O(V)
void initSets() {
    S.clear();
    memset(T, 0, sizeof(bool) * n);

    FOR(x, 0, n) {
        if (x2y[x] == -1) {
            S.push_back(x); // pick free vertex x
            break;
        }
    }
}

// O(V)
// when x is new to S, update slack for all y that is not in T
void updateSlack(int x) {
    FOR(y, 0, n) {
        int d = cost[x][y] - lx[x] - ly[y];
        if (!T[y] && slack[y] > d) {
            slack[y] = d;
            slack2X[y] = x;
        }
    }
}
// 처음으로 0을 만드는 x에 대해 (y를 N(S)에 새롭게 집어넣는 x) slack2X[y] = x 를 저장

// O(V)
// find a = min(cost[x][y] - l[x] - l[y]) for (all x in S and all y not in T)
int findMinSlack() {
    int ret;
    int mn = INF;
    FOR(y, 0, n) {
        if (!T[y] && slack[y] >= 0 && slack[y] < mn) {
            mn = slack[y];
            ret = y;
        }
    }
    return ret;
}

// O(V)
// 기존 l(x) + l(y) == cost(x, y)인 S, T는 유지 시키면서
// min(cost(x, y) - l(x) - l(y)) (for x in S and y not in T)를 0으로 만든다 (l(x)를 그 만큼 증가시킨다)
void updateLabels(int a) {
    for (auto x : S) {
        lx[x] += a;
    }

    FOR(y, 0, n) {
        if (T[y]) {
            ly[y] -= a;
        } else {
            slack[y] -= a;
        }
    }
}

// x is slack2X[y], which makes x be in S (because slack only updates when x joins S)
// y is free and slack[y] == 0 (because y is from N(S))
// i.e. slack2X[y] == x means e(x, y) is E - M
// O(V)
void updateMatchingGraph(int x, int y) {
    while (x2y[x] != -1) {
        // x already has matching pair, alternate it
        // alternate previouse y
        int prevY = x2y[x];
        x2y[x] = y;
        y2x[y] = x;
        // prev y is now free
        x = slack2X[prevY];
        y = prevY;
    }
    // if x is free, x must be u, inital free vertex
    x2y[x] = y;
    y2x[y] = x;
}
// questions: 이 재귀 함수가 동작하는 이유는? (즉, u-y alternating path를 잘 찾는 이유는?)
// 귀납적으로 생각해보자. 맨 처음, initial free vertex u는 아직 matching 되지 않은 상황이다.
//
// u에 의해 업데이트 된 slack이 0인 y가 선택된다. 이것이 free면 함수는 한번에 종료된다. (e(u, y) in N(S))
// free가 아니라면 이미 matching된 x가 있고, 이것이 S에 새로 들어온다. 이 x로 slack을 업데이트.
//
// 다음으로 선택되는 y는 새로 들어온 x에 의해 0이 되었거나, u에 의해 0이 된 것이다.
// u에 의해 0이 된 y가 선택되면 앞서 설명한 상황과 같은것이 반복된다.
//
// x에 의해 0이 된 y가 선택되고 이게 free라면, x와 y는 새로 연결되고 x와 이미 연결되어 있던 y는
// u에 의해 0이 되었으나 이미 x와 연결되어 있었던 그것이다. 따라서 slack2X[y] = u.
// x에 의해 0이 된 y가 free가 아니라면 또 다른 x'에 이미 매칭되어있다. 이것이 S에 새로 들어온다.
//
// 다음으로 선택되는 y는 u, x 혹은 x'에 의해 0이 된 것 이므로 크기가 1 큰 앞선 상황과 동일하다.

// O(V^2)
void augment() {
    FOR(y, 0, n) {
        slack[y] = INF;
    }
    memset(slack2X, -1, sizeof(int) * n);

    // O(V) loops
    while (true) {
        int x = S.back();
        // new vertex comes in X, update slack
        updateSlack(x); // O(V)

        // try to pick y in N - T
        int y = findMinSlack(); // O(V)

        // if slack[y] == 0, that means y is in N(S) - T
        // if not, N(S) = T, need to update labels
        // after the update, slack[y] becomes 0, which makes it be in N(S) - T;

        if (slack[y] != 0) {
            updateLabels(slack[y]); // O(V)
        }

        if (y2x[y] == -1) {
            // found augment path: u-y;
            updateMatchingGraph(slack2X[y], y); // O(V), once per the whole loop
            matchingCnt++;
            return;
        } else {
            // extend alternating tree
            S.push_back(y2x[y]);
            T[y] = true;
        }
    }
}

// minimum assignment problem
// i.e.  bipartite perfect matching with minumum cost
// O(V^3)
int hungarian() {
    initLabels();

    // O(V) loops
    while (matchingCnt != n) {
        initSets(); // O(V) per loop
        augment();  // O(V^2) per loop
    }

    FOR(i, 0, n) {
        ans += lx[i] + ly[i];
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> cost[i][j];
        }
    }

    cout << hungarian() << '\n';

    return 0;
}