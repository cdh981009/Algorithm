#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
constexpr int logN = 16;
int sparseAncestor[N + 1][logN + 1];
long long dist[N + 1][logN + 1];
vector<pair<int, int>> edge[N + 1];
int depth[N + 1];

void dfs(int node) {
    for (auto p : edge[node]) {
        int child = p.first;
        int cost = p.second;
        if (sparseAncestor[node][0] == child)
            continue;
        sparseAncestor[child][0] = node;
        depth[child] = depth[node] + 1;
        dist[child][0] = cost;
        dfs(child);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v, c;
        cin >> u >> v >> c;
        edge[u].push_back({v, c});
        edge[v].push_back({u, c});
    }

    dfs(1);
    FOR_(i, 1, logN) {
        FOR_(j, 1, n) {
            int m = sparseAncestor[j][i - 1];
            long long d = dist[j][i - 1];
            sparseAncestor[j][i] = sparseAncestor[m][i - 1];
            dist[j][i] = d + dist[m][i - 1];
        }
    }

    int q; cin >> q;
    FOR(i, 0, q) {
        int type, u, v;
        cin >> type >> u >> v;
        int ou, ov;
        ou = u;
        ov = v;
        int k;
        if (type == 2) {
            cin >> k;
        }

        bool swapped = false;
        if (depth[u] < depth[v]) {
            swap(u, v);
            swapped = true;
        }

        long long uDist = 0;
        long long vDist = 0;
        int uCnt = 0;
        int vCnt = 0;
        while (depth[u] > depth[v]) {
            int diff = depth[u] - depth[v];
            int cnt = 0;
            int num = 1;
            while (num * 2 <= diff) {
                num *= 2;
                cnt++;
            }
            uDist += dist[u][cnt];
            uCnt += num;
            u = sparseAncestor[u][cnt];
        }
        // now depth is same
        // cout << "depth is same " << u << " " << v << endl;
        if (swapped) {
            swap(u, v);
            swap(uDist, vDist);
            swap(uCnt, vCnt);
        }

        long long d;
        int cnt;
        if (u != v) {
            int step = logN;
            for (int step = logN; step >= 0; step -= 1) {
                // binary searching lca, keeping min and max values to the lca.
                while (sparseAncestor[v][step] != sparseAncestor[u][step]) {
                    uDist += dist[u][step];
                    vDist += dist[v][step];
                    uCnt += (1 << step);
                    vCnt += (1 << step);
                    v = sparseAncestor[v][step];
                    u = sparseAncestor[u][step];
                }
            }
            uDist += dist[u][0];
            vDist += dist[v][0];
            uCnt += 1;
            vCnt += 1;
            
        }

        d = uDist + vDist;
        cnt = uCnt + vCnt;
        //cout << d << " " << cnt << endl;
        int kth;
        if (type == 2) {
            k--; // 지나간 edge 숫자로 보기 위해 -1 해줌
            kth = ou;
            if (k > uCnt) {
                k = cnt - k;
                kth = ov;
            }
            
            while (k > 0) {
                int cnt = 0;
                int num = 1;
                while (num * 2 <= k) {
                    num *= 2;
                    cnt++;
                }
                kth = sparseAncestor[kth][cnt];
                //cout << kth << endl;
                k -= num;
            }
        }

        cout << (type == 1 ? d : kth) << "\n";
    }
    return 0;
}