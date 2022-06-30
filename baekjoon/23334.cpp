#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
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

constexpr int N = 1100;
constexpr int M = 100;

ll n, m, k, ans;
ll arr[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    struct Team {
        ll m[3];
        string name;
    };

    vector<Team> v;
    cin >> n;
    rep(i, 0, n) {
        ll g, s, b;
        string str, name;
        cin >> g >> s >> b;
        getline(cin, str);
        rep(i, 1, str.size()) {
            name.push_back(str[i]);
        }

        v.push_back({g, s, b, name});
    }

    sort(v.begin(), v.end(), [](auto &l ,auto &r) {
        rep(i, 0, 3)
            if (l.m[i] != r.m[i]) return l.m[i] < r.m[i];
    });

    cout << v.back().name << '\n';

    return 0;
}