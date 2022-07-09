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

constexpr int N = 1030;
constexpr int M = 100;

int n, m;
ll arr[N];
bool picked[N];
vector<ll> vec;

void solve(int ind) {
    if (ind == m) {
        for (auto x : vec)
            cout << x << ' ';
        cout << '\n';
        return;
    }

    rep(i, 0, n) {
        if (!picked[i]) {
            picked[i] = true;
            vec.push_back(arr[i]);
            solve(ind + 1);
            vec.pop_back();
            picked[i] = false;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    rep(i, 0, n) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    solve(0);

    return 0;
}