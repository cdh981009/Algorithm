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

constexpr int N = 20000;
constexpr int M = 26;

ll n, m, k, q, ans;
bool a[N][M];
bool b[M][M];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<string> stmp;

    ll n, m;
    cin >> n >> m;
    bool pos = true;

    rep(i, 0, m) {
        string str;
        cin >> str;

        if (stmp.count(str)) pos = false;
        stmp.insert(str);

        rep(j, 0, n) {
            int c = str[j] - 'A';
            b[c][j] = true;
        }
    }

    rep(i, 0, M) {
        int cnt = 0;
        rep(j, 0, M) {
            cnt += b[i][j];
            if (cnt >= 2) {
                pos = false;
                break;
            }
        }
        if (!pos) break;
    }

    vector<string> ans;
    ll sm = 1;
    rep(i, 0, n) {
        string s;
        ll cnt = 0;
        rep(j, 0, M) {
            if (b[j][i]) {
                s.push_back(j + 'A');
                cnt++;
            }
        }
        sm *= cnt;
        ans.push_back(s);
    }
    
    if (sm != m)
        pos = false;

    if (pos) {
        cout << "YES\n";
        for (auto &s : ans)
            cout << s << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}