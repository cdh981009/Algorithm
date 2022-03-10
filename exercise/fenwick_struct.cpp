#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 501010;
constexpr int M = 100;

struct Fenwick {
    vi a;
    Fenwick(int sz) {
        a = vi(sz + 1, 0);
    }

    void update(int x) {
        x++;
        while (x < a.size()) {
            a[x]++;
            x += (x&-x);
        }
    }

    int cnt(int x) {
        x++;
        int ret = 0;
        while (x) {
            ret += a[x];
            x -= (x&-x);
        }

        return ret;
    }
};

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
        int n; cin >> n;
        vi a(n, - 1);
        bool pos = false;
        FOR(i, 0, n) {
            int x;
            cin >> x;
            x--;
            if (a[x] != -1) pos = true;
            a[x] = i;
        }
        
        ll cnt = 0;
        if (!pos) {
            // all is distinct
            // count inversion
            Fenwick fw(n);
            FOR(i, 0, n) {
                cnt += (i - fw.cnt(a[i]));
                fw.update(a[i]);
            }

            pos = (cnt % 2 == 0);
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }

    return 0;
}