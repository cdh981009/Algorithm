#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;
constexpr int M = 100;

int n, q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    set<int> s; // set of potentially sick indices
    vector<int> a(n, INF); // a[l] = min r, for sick ranges of [l, r]
    FOR_(i, 0, n) {
       s.insert(i); 
    }

    FOR(i, 0, q) {
        int t; cin >> t;
        if (t == 0) { // update
            int l, r, x; cin >> l >> r >> x;
            l--; r--;
            if (x == 0) { // not sick
                auto it = s.lower_bound(l);
                while (true) {
                    if (*it > r) {
                        break;
                    }
                    int x = a[*it];
                    it = s.erase(it);
                    a[*it] = min(a[*it], x); // merge sick ranges
                }
            } else { // sick
                auto it = s.lower_bound(l);
                a[*it] = min(a[*it], r);
            }
        } else { // query
            int j; cin >> j;
            j--;
            auto it = s.lower_bound(j);
            if (*it == j) {
                int r = a[j];
                it++;
                if (*it > r) {
                    cout << "YES";
                } else {
                    cout << "N/A";
                }
            } else { // not sick
                cout << "NO";
            }
            cout << '\n';
        }
    }    

    return 0;
}