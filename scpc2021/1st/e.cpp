#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10101;
constexpr int K = 20101;

using ll = long long;

int n, k;

int root[N];
int delta[N];
bool cf[N];

int find(int x) {
    if (x == root[x]) {
        return x;
    } else {
        find(root[x]);
        delta[x] += delta[root[x]];
        root[x] = root[root[x]];
        return root[x];
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y, int d) {
    find(x);
    find(y);

    d = delta[x] - delta[y] - d;

    x = root[x];
    y = root[y];
    
    if (x == y)
        return;

    root[y] = x;
    delta[y] = d;
    cf[x] |= cf[y];
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
        memset(delta, 0, sizeof(int) * N);
        memset(cf, 0, sizeof(bool) * N);

        FOR(i, 0, n) {
            root[i] = i;
        }

        FOR(i, 0, k) {
            int t, a, b, d;
            cin >> t >> a >> b;
            a--;
            b--;
            
            if (t == 1) {
                cin >> d;
                if (same(a, b)) {
                    if (delta[a] - delta[b] != d) {
                        cf[root[a]] = true;
                    }
                } else {
                    unite(a, b, d);
                }
            } else {
                if (!same(a, b)) {
                    cout << "NC\n";
                } else if (cf[root[a]]) {
                    cout << "CF\n";
                } else {
                    cout << delta[a] - delta[b] << '\n';
                }
            }
        }
    }

    return 0;
}