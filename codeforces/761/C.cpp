#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1, 0);
        vector<int> a;
        vector<int> perm;
        FOR(i, 0, n) {
            int x; cin >> x;
            if (x <= n && cnt[x] == 0) cnt[x]++;
            else a.push_back(x);
        }
        FOR_(i, 1, n) if (cnt[i] == 0) perm.push_back(i);
        sort(a.begin(), a.end());

        bool pos = true;
        FOR(i, 0, perm.size()) {
            if (a[i] - perm[i] <= perm[i]) {
                pos = false;
                break;
            }
        }

        cout << (pos ? (int)perm.size() : -1) << '\n';
    }
    return 0;
}