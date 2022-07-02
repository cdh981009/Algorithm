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

constexpr int N = 201010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    double up, down;
    up = down = 0;

    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<pll> times;

    rep(i, 0, n) {
        ll t = 0, l;
        string str;
        cin >> str;
        ll year = stoi(str.substr(0, 4));
        ll month = stoi(str.substr(5, 2));
        ll day = stoi(str.substr(8, 2));

        day += (year - 2019) * 365;
        if (year > 2020) day += 1;

        rep(i, 1, month) {
            day += mon[i - 1];
        }
        if (year == 2020 && month > 2) day += 1;
        t += day * 24 * 60 * 60;

        cin >> str;
        ll hr, mn, sc;
        hr = stoi(str.substr(0, 2));
        mn = stoi(str.substr(3, 2));
        sc = stoi(str.substr(6, 2));

        hr *= 60 * 60;
        mn *= 60;
        sc += hr + mn;
        t += sc;

        cin >> l;
        times.push_back({t, l});
    }

    sort(times.begin(), times.end());

    rep(i, 0, n) {
        double p = max(pow(0.5, (times.back().first - times[i].first) / (365.0 * 24 * 60 * 60)), pow(0.9, n - i - 1));
        down += p;
        up += p * times[i].second;
    }

    if (n == 0)
        cout << 0 << '\n';
    else
        cout << round(up / down) << '\n';

    return 0;
}