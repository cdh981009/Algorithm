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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, a, b, c;
    cin >> v >> a >> b >> c;
    int x = 0;
    while (v >= 0) {
        if (x == 0) {
            if (v - a >= 0)
                v -= a;
            else
                break;
        } else if (x == 1) {
            if (v - b >= 0)
                v -= b;
            else
                break;
        } else {
            if (v - c >= 0)
                v -= c;
            else
                break;
        }
        x = (x + 1) % 3;
    }

    if (x == 0)
        cout << 'F';
    else if (x == 1)
        cout << 'M';
    else
        cout << 'T';
    cout << '\n';

    return 0;
}