#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5 + 1;
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
        int n, ans;
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) {
            cin >> a[i];
        }

        vector<int> v;
        FOR(i, 0, n) {
            if (v.empty() || a[i] > v.back()) {
                v.push_back(a[i]);
                continue;
            }
            int x = v.back();
            while (!v.empty() && a[i] < v.back()) {
                v.pop_back();
            }
            v.push_back(x);
        }

        cout << v.size() << '\n';
    }
    return 0;
}