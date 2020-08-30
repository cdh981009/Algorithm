#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int K = 2e3;
constexpr int N = 15e2;

int n, k, m;
int node[K][2];
pair<pair<int, int>, pair<int, int>> edge[K][2]; // outgoing edge
// 첫번째 엣지는 weight가 1, 두번째는 0인 엣지를 표현
int cache[K][2][N + 1];
int ans;

int main(int argc, char** argv) {
    int T, test_case;
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        ans = 0;
        // 노드의 index를 이차원으로 표현하자
        // [k][2] := {사다리 인덱스, 위치}
        cin >> n >> k >> m;
        FOR(i, 0, k) {
            edge[i][0] = edge[i][1] = {{-1, -1}, {-1, -1}};
        }
        
        // n번째 줄의 가장 최근 노드
        vector<pair<int, int>> recentLadder(n + 1, {-1, 0});
        vector<pair<int, int>> start(n + 1, {-1, -1});
        FOR(i, 0, k) {
            int u, v; cin >> u >> v;
            node[i][0] = u;
            node[i][1] = v;
            if (recentLadder[u].first == -1) {
                start[u] = {i, 0};
            } else {
                edge[recentLadder[u].first][recentLadder[u].second].first =
                edge[recentLadder[u].first][(recentLadder[u].second) ^ 1].second = {i, 0};
                // 부모로부터 연결
            }
            recentLadder[u] = {i, 0};

            if (recentLadder[v].first == -1) {
                start[v] = {i, 1};
            } else {
                edge[recentLadder[v].first][recentLadder[v].second].first =
                edge[recentLadder[v].first][(recentLadder[v].second) ^ 1].second = {i, 1};
                // 부모로부터 연결
            }
            recentLadder[v] = {i, 1};
        }
        // 가장 끝 노드들에 대해 처리해준다
        // cache[k][i][n] := 노드[k][i]가 줄 n까지 가는데 최단 거리;
        /*
        FOR_(i, 1, n) {
            cache[recentLadder[i].first][recentLadder[i].second][
                node[recentLadder[i].first][recentLadder[i].second]
            ] = 1;
            cache[recentLadder[i].first][recentLadder[i].second][
                node[recentLadder[i].first][(recentLadder[i].second) ^ 1]
            ] = 0;
            cache[recentLadder[i].first][(recentLadder[i].second) ^ 1][
                node[recentLadder[i].first][recentLadder[i].second]
            ] = 0;
        }
        */
        // dp 채우기
        for (int i = k - 1; i >= 0; --i) {
            FOR(l, 0, 2) {
                FOR_(j, 1, n) {
                    auto &ref = cache[i][l][j] = INF;
                    if (edge[i][l].first.first == -1) {
                        if (j == node[i][l])
                            ref = 1;
                    } else {
                        ref = min(ref, cache[edge[i][l].first.first][edge[i][l].first.second][j] + 1);
                    }

                    if (edge[i][l].second.first == -1) {
                        if (j == node[i][l^1])
                            ref = 0;
                    } else {
                        ref = min(ref, cache[edge[i][l].second.first][edge[i][l].second.second][j]);
                    }
                }
            }
        }

        /*
        for (int i = 0; i < k; ++i) {
            FOR(l, 0, 2) {
                cout << i << " " << l << endl;
                FOR_(j, 1, n) {
                    cout << cache[i][l][j] << " ";
                }
                cout << endl;
            }
        }
        FOR_(i, 1, n) {
            FOR_(j, 1, n)
                cout << "i: " << i << " j: " << j << " val: " <<
                    cache[start[i].first][start[i].second][j] << endl;
        }
        */
        FOR(i, 0, m) {
            int u, v; cin >> u >> v;
            int res = (start[u].first == -1) ? (v == u ? 0 : INF) : cache[start[u].first][start[u].second][v];
            //cout << res << endl;
            ans += (res == INF ? -1 : res);
        }
        cout << "Case #" << test_case + 1 << endl;
        cout << ans << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}