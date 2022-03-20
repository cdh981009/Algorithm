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
using mii = map<int, int>;
using mll = map<ll, ll>;


constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<int> s;
    FOR_(i, 1, 2 *n + 1) {
        s.insert(i);
    }

    while (!s.empty()) {
        cout << *s.begin() << '\n';
        s.erase(s.begin());
        cout.flush();
        int x; cin >> x;
        if (x == 0) break;
        s.erase(x);
    }


    return 0;
}