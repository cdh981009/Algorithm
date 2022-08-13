#include <bits/stdc++.h>

using namespace std;

#define INF (1e9+7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, m, k, q, ans;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> ind(n + 1, -1);
        vector<bool> ch(n + 1, false);
        rep(i, 0, n) {
            cin >> a[i];
            ind[a[i]] = i;
        }

        int j = -1;
        for (int i = n - 1; i >= 1; --i) {
            if (a[i-1] > a[i]) {
                j = i - 1;
                break;
            }
        }

        if (j == -1) ans = 0;
        else {
            ans = 0;
            int end = j;
            j = 0;
            while (j <= end) {
                int x = a[j];
                if (ch[x] == false) {
                    ans++;
                    ch[x] = true;
                    end = max(end, ind[x]);
                }
                j++;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}