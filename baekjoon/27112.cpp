#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define repr_(i, a, b) for (int i = (a); i >= (b); --i)
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

constexpr int N = 5010;
constexpr int M = 100;

ll n, m, k, q, ans;
int number[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    
    cin >> n;
    vpii v;
    rep(i, 0, n) {
        int d, t;
        cin >> d >> t;
        v.push_back({d, t});
    }

    sort(v.begin(), v.end());

    int off = 0;
    int work = 0;

    bool pos = true;

    rep(i, 1, 101010) {
        if (i % 7 == 0 || i % 7 == 6) continue;
        if (work == v.size()) break;
        auto &[d, t] = v[work];

        if (d < i) {
            off++;
            if (d < off) {
                pos = false;
                break;
            }
            t--;
            i--;
        } else {
            t--;
        }

        if (t == 0) work++;
    }

    if (pos) cout << off << '\n';
    else cout << -1 << '\n';

    return 0;
}