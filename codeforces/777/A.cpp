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

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string str;
        int x = 0;
        bool t = true;
        while (x < n) {
            if (t)
                str.push_back('2');
            else
                str.push_back('1');
            x += t ? 2 : 1;
            t = !t;
        }
        if (x > n) {
            str.clear();
            t = false;
            x = 0;
            while (x < n) {
                if (t)
                    str.push_back('2');
                else
                    str.push_back('1');
                x += t ? 2 : 1;
                t = !t;
            }
        }

        cout << str << '\n';
    }

    return 0;
}