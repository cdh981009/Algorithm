#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int n, m, q;
int ans;
int indeg[N];
int cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cnt = n;

    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        if (u < v)
            swap(u, v);
        if (indeg[v] == 0)
            cnt--;
        indeg[v]++;
    }

    cin >> q;

    FOR(i, 0, q) {
        int t, u, v;
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            if (u < v)
                swap(u, v);
            if (indeg[v] == 0)
                cnt--;
            indeg[v]++;
        } else if (t == 2) {
            cin >> u >> v;
            if (u < v)
                swap(u, v);
            indeg[v]--;
            if (indeg[v] == 0)
                cnt++;
        } else {
            cout << cnt << '\n';
        }
    }

    return 0;
}