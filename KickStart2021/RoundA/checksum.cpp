#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10000;

using pii = pair<int, int>;
vector<pii> edges[N];
bool visited[N];
int dist[N];

int n;
int ans;
int sum;
int aux;

// maximum spanning tree
int mst(int start) {
    if (edges[start].empty()) {
        visited[start] = true;
        return 0;
    }
    
    int res = 0;

    FOR(i, 0, N) {
        dist[i] = -INF;
    }
    dist[start] = 0;

    while (true) {
        int now = -1;
        int maxDist = -INF;
        FOR(i, 0, 2 * n) {
            if (!visited[i] && maxDist < dist[i]) {
                now = i;
                maxDist = dist[i];
            }
        }

        if (now == -1)
            break;
        res += maxDist;
        visited[now] = true;

        FOR(i, 0, edges[now].size()) {
            auto &edge = edges[now][i];
            dist[edge.first] = max(dist[edge.first], edge.second);
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(caseNum, 1, tc) {
        memset(visited, 0, sizeof(bool) * N);
        memset(edges, 0, sizeof(vector<pii>) * N);

        cin >> n;
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                cin >> aux;
            }
        }

        sum = 0;
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                cin >> aux;
                if (aux == 0)
                    continue;
                edges[i].push_back({j + n, aux});
                edges[j + n].push_back({i, aux});
                sum += aux;
            }
        }
        FOR(i, 0, n) {
            cin >> aux;
        }
        FOR(i, 0, n) {
            cin >> aux;
        }

        FOR(i, 0, n) {
            if (!visited[i])
                sum -= mst(i);
        }

        ans = sum;
        
        cout << "Case #" << caseNum << ": " << ans << '\n';
    }
    return 0;
}