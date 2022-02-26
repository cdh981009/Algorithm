#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    multiset<int> a;
    vector<int> b(m);
    FOR(i, 0, n) {
        int x; cin >> x;
        a.insert(x);
    }
    FOR(i, 0, m) cin >> b[i];

    bool pos = true;

    FOR(i, 0, m) {
        auto it = a.lower_bound(b[i]);
        if (it == a.end() || *it != b[i]) {
            pos = false;
            break;
        } else {
            a.erase(it);
        }
    }

    cout << (pos ? "Yes" : "No") << '\n';
    
    return 0;
}