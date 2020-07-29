#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using pii = pair<int, int>;

constexpr int W = 1e3;
pii pos[W + 1];
int dp[W + 1][2][W + 1];
tuple<int, int, int> nxt[W + 1][2][W + 1];
int n, w;
pii init0, init1;

int dist(const pii& lhs, const pii& rhs) {
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

// 지금까지 사건 [1 ... curr) 를 처리했고,
// car은 pos[loc]에 해당하는 위치에 있으며
// 다른 한 자동차는 pos[curr - 1]에 해당하는 위치에 있을 때
// 앞으로 사건들을 처리할 때 이동하는 거리의 최소값
int minDist(int curr, int car, int loc) {
    if (curr > w) // 모든 사건 처리
        return 0;

    int& ref = dp[curr][car][loc];
    auto& nextRef = nxt[curr][car][loc];
    if (ref != -1)
        return ref;

    auto carPos0 = (car == 0) ? (loc == 0 ? init0 : pos[loc])
                              : (curr == 1 ? init0 : pos[curr - 1]);

    auto carInd0 = (car == 0) ? loc : curr - 1;

    auto carPos1 = (car == 1) ? (loc == 0 ? init1 : pos[loc])
                              : (curr == 1 ? init1 : pos[curr - 1]);

    auto carInd1 = (car == 1) ? loc : curr - 1;

    // 0번 차가 처리
    ref = minDist(curr + 1, 1, carInd1) + dist(carPos0, pos[curr]);
    nextRef = {curr + 1, 1, carInd1};
    // 1번 차가 처리
    int carOneResult = minDist(curr + 1, 0, carInd0) + dist(carPos1, pos[curr]);
    if (carOneResult < ref) {
        ref = carOneResult;
        nextRef = {curr + 1, 0, carInd0};
    }
    
    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(int) * (W + 1) * (W + 1) * 2);

    cin >> n >> w;
    init0 = {1, 1};
    init1 = {n, n};
    FOR_(i, 1, w) {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }

    int dist = minDist(1, 0, 0);
    cout << dist << "\n";
    auto& curr = nxt[1][0][0];
    while (true) {
        //cout << get<0>(curr) << " " << get<1>(curr) << " " << get<2>(curr) << endl;
        cout << (get<1>(curr) == 0 ? 2 : 1) << "\n";
        if (get<0>(curr) > w)
            break;
        curr = nxt[get<0>(curr)][get<1>(curr)][get<2>(curr)];
    } 

    return 0;
}