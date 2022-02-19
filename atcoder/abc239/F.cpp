#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

ll n, m;
int d[N];
vector<int> edges[N];

int root[N];
int sz[N];
vector<int> need[N];
vector<pii> ans;

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    if (sz[x] < sz[y])
        swap(x, y);

    root[y] = x;
    sz[x] += sz[y];
}

int size(int x) {
    return sz[find(x)];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    FOR(i, 0, n) {
        cin >> d[i];
        root[i] = i;
    }

    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    bool pos = true;

    ll sum = 0;
    FOR(i, 0, n) {
        sum += d[i] - edges[i].size();
        if (edges[i].size() > d[i]) {
            pos = false;
            break;
        }
        for (auto x : edges[i]) {
            if (x > i) continue;
            if (same(x, i)) {  // cycle
                pos = false;
                break;
            } else {
                unite(x, i);
            }
        }
    }

    if (sum % 2 || sum / 2 != n - m - 1) {
        pos = false;
    }

    if (pos) {
        vector<bool> cnt(n);
        vector<int> comp;

        FOR(i, 0, n) {
            int x = find(i);
            while ((d[i]--) > (int)edges[i].size()) {
                need[x].push_back(i);
            }
            if (cnt[x] == 0) {
                cnt[x] = true;
                comp.push_back(x);
            }
        }

        sort(comp.begin(), comp.end(), [&](const int& l, const int& r) {
            return need[l].size() > need[r].size();
        });

        FOR(i, 1, comp.size()) {
            int x = comp[i];
            if (need[x].size() == 0 || need[comp[0]].size() == 0) {
                pos = false;
                break;
            } else {
                ans.push_back({need[x].back(), need[comp[0]].back()});
                need[x].pop_back();
                need[comp[0]].pop_back();

                for (auto& y : need[x])
                    need[comp[0]].push_back(y);
            }
            unite(comp[0], comp[i]);
        }
    }

    if (!pos) {
        cout << -1 << '\n';
    } else {
        assert(ans.size() == n - m - 1);
        for (auto& [x, y] : ans) {
            cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }

    return 0;
}