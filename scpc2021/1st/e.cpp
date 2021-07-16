#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;
constexpr int K = 201010;

using ll = long long;

int n, k;

int fenwick[N];
int root[N];
bool cf[N];
vector<int> edge[N];

int cnt;
int ind[N];
int sub[N];

int find(int x) {
    return x == root[x] ? x : root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    root[y] = x;
    cf[x] |= cf[y];
}

struct Query {
    int t, a, b, d;
} q[K];

void dfs(int node) {
    ind[node] = ++cnt;
    sub[node] = ind[node];

    FOR(i, 0, edge[node].size()) {
        int child = edge[node][i];
        dfs(child);
        sub[node] = max(sub[node], sub[child]);
    }
}

void update(int x, int v) {
    int i;
    
    i = ind[x];
    while (i <= n) {
        fenwick[i] += v;
        i += (i & -i);
    }

    i = sub[x] + 1;
    while (i <= n) {
        fenwick[i] -= v;
        i += (i & -i);
    }
}   

int getVal(int x) {
    int sum = 0;
    x = ind[x];

    while (x) {
        sum += fenwick[x];
        x &= x - 1;
    }

    return sum;
}

int main(int argc, char** argv) {
    int T, tc;

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cout << "Case #" << tc + 1 << '\n';

        cin >> n >> k;
        memset(fenwick, 0, sizeof(int) * N);
        memset(edge, 0, sizeof(vector<int>) * n);
        cnt = 0;

        FOR(i, 0, n) {
            root[i] = i;
        }

        FOR(i, 0, k) {
            auto& query = q[i];
            cin >> query.t >> query.a >> query.b;
            query.a--;
            query.b--;
            if (query.t == 1) {
                cin >> query.d;
                if (!same(query.a, query.b)) {
                    edge[find(query.a)].push_back(find(query.b));
                    unite(query.a, query.b);
                }
            }
        }

        FOR(i, 0, n) {
            if (find(i) == i) {
                dfs(i);
            }
        }

        FOR(i, 0, n) {
            root[i] = i;
            cf[i] = false;
        }

        FOR(i, 0, k) {
            auto& query = q[i];
            if (query.t == 1) {
                if (same(query.a, query.b)) {
                    if (getVal(query.a) - getVal(query.b) != query.d) {
                        cf[find(query.a)] = true;
                    }
                } else {
                    update(find(query.b), getVal(query.a) - getVal(query.b) - query.d);
                    unite(query.a, query.b);
                }
            } else {
                if (!same(query.a, query.b)) {
                    cout << "NC\n";
                } else if (cf[find(query.a)]) {
                    cout << "CF\n";
                } else {
                    cout << getVal(query.a) - getVal(query.b) << '\n';
                }
            }
            // FOR(i, 0, n) {
            //     cout << getVal(i) << ' ';
            // }
            // cout << endl;
        }
    }

    return 0;
}