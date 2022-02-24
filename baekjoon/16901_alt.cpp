#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 201010;
constexpr int L = 29;

vector<int> a;
int trie[N * L][2], cnt[N * L], indx[N * L];
bool visited[N];
int tp = 0;

void insert(int ind) {
    int x = a[ind];
    int c = 0;
    for (int i = L; i >= 0; --i) {
        bool bit = ((x >> i) & 1);
        if (!trie[c][bit]) trie[c][bit] = ++tp;
        c = trie[c][bit];
        cnt[c]++;
    }
    indx[c] = ind;
}

void erase(int ind) {
    int x = a[ind];
    int c = 0;
    for (int i = L; i >= 0; --i) {
        bool bit = ((x >> i) & 1);
        c = trie[c][bit];
        cnt[c]--;
    }
}

int query(int ind) {
    int x = a[ind];
    int c = 0;
    for (int i = L; i >= 0; --i) {
        bool bit = ((x >> i) & 1);
        if (cnt[trie[c][bit]] == 0)
            c = trie[c][!bit];
        else
            c = trie[c][bit];
    }
    return indx[c];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> compOf(n);
    vector<vector<int>> elmOf(n);
    ll ans = 0;

    a.resize(n);
    FOR(i, 0, n)
        cin >> a[i];
    sort(a.begin(), a.end());
    n = unique(a.begin(), a.end()) - a.begin();
    FOR(i, 0, n) {
        insert(i);
        compOf[i] = i;
        elmOf[i].push_back(i);
    }

    int cnt = 0;
    while (cnt != n - 1) {
        memset(visited, 0, sizeof(bool) * n);
        FOR(i, 0, n) {
            int comp = compOf[i];
            if (visited[comp] || elmOf[comp].empty()) continue;
            visited[comp] = true;

            for (auto &x : elmOf[comp]) {
                erase(x);
            }

            int res = INT32_MAX;
            int target;

            for (auto &x : elmOf[comp]) {
                int y = query(x);
                if ((a[x] ^ a[y]) < res) {
                    res = (a[x] ^ a[y]);
                    target = compOf[y];
                }
            }

            ans += res;

            for (auto &x : elmOf[comp]) {
                insert(x);
            }

            for (auto &x : elmOf[target]) {
                compOf[x] = comp;
                elmOf[comp].push_back(x);
            }
            elmOf[target].clear();

            if (++cnt == n - 1) break;
        }
    }

    cout << ans << '\n';
    return 0;
}