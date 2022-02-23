#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        FOR(i, 0, n) cin >> a[i];
        if (n % 2) {
            cout << -1 << '\n';
        } else {
            map<int, int> cnt;
            for (auto &x : a) {
                cnt[x]++;
            }
            bool pos = true;
            for (auto const &[k, v] : cnt) {
                if (v % 2) {
                    pos = false;
                    break;
                }
            }
            if (!pos) {
                cout << -1 << '\n';
            } else {
                // TODO
                int indx = 1;
                vector<int> segs;
                vector<pii> ans;
                while (true) {
                    vector<int> aux;
                    if (a.size() == 2) {
                        segs.emplace_back(2);
                        break;
                    } else {
                        int e;
                        FOR(i, 1, a.size()) {
                            if (a[i] == a[0]) {
                                e = i;
                                break;
                            } else {
                                aux.push_back(a[i]);
                            }
                        }
                        
                        FOR(i, 0, aux.size()) {
                            ans.emplace_back(indx + e + i, aux[i]);
                        }

                        reverse(aux.begin(), aux.end());
                        segs.push_back(2 + 2 * aux.size());
                        indx += e + aux.size() + 1;

                        FOR(i, e + 1, a.size()) {
                            aux.push_back(a[i]);
                        }
                        
                        swap(aux, a);
                    }
                }

                cout << ans.size() << '\n';
                for (auto &[i, c] : ans) {
                    cout << i << ' ' << c << '\n';
                }
                cout << segs.size() << '\n';
                for (auto &x : segs) {
                    cout << x << ' ';
                }
                cout << '\n';
            }
        }
    }

    return 0;
}