// 11780: 플로이드 2
// https://www.acmicpc.net/problem/11780
#include <bits/stdc++.h>

using namespace std;

#define INF (1e7 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101;

int n, m;
int adj[N][N];
int nxt[N][N];
int len[N][N];

void floyd() {
    FOR_(k, 1, n) {
        FOR_(i, 1, n) {
            FOR_(j, 1, n) {
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    len[i][j] = len[i][k] + len[k][j] - 1;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    FOR_(i, 1, n) {
        FOR_(j, 1, n) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }

    FOR(i, 0, m) {
        int s, e, c;
        cin >> s >> e >> c;
        if (adj[s][e] > c) {
            adj[s][e] = c;
            nxt[s][e] = e;
            len[s][e] = 2;
        }
    }

    floyd();

    FOR_(i, 1, n) {
        FOR_(j, 1, n) {
            cout << (adj[i][j] >= INF ? 0 : adj[i][j]) << ' ';
        }
        cout << '\n';
    }

    FOR_(i, 1, n) {
        FOR_(j, 1, n) {
            if (adj[i][j] >= INF || i == j) {
                cout << 0 << '\n';
            } else {
                cout << len[i][j] << ' ';
                int curr = i;
                while (true) {
                    cout << curr << ' ';
                    if (curr == j)
                        break;
                    curr = nxt[curr][j];
                }
                cout << '\n';
            }
        }
    }

    return 0;
}