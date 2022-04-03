#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 10)
#define fi first
#define se second
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep_(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (ll i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

ll n, k, m, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    rep_(testcase, 1, tc) {
        srand(time(NULL));

        cin >> n >> k;
        vl ps(n+1, -1);
        ll r, p;
        ll sum = 0, ans = 0;
        cin >> r >> p;
        ps[r] = p;
        sum += p;
        
        rep(i, 0, k) {
            if (i % 2 == 0) {
                int room = (rand() % n + 1);
                cout << "T " << room << '\n';
                cout.flush();
                cin >> r >> p;
                ps[r] = p;
                sum += p;
            } else {
                cout << "W\n";
                cout.flush();
                cin >> r >> p;
                ps[r] = p;
            }
        }

        ll cnt = 0;
        ll avg = sum / (k/2);
        sum = 0;
        rep_(i, 1, n) {
            if (ps[i] == -1) cnt++;
            else sum += ps[i];
        }

        ans += avg * cnt;
        ans += sum;
        

        cout << "E " << ans/2 << '\n';
        cout.flush();

    }

    return 0;
}