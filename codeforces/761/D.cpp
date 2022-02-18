#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;
constexpr int M = 100;

struct tup {
    int a[3];
};

int main() {
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        auto query = [](int a, int b, int c) {
            cout << "? " << a << ' ' << b << ' ' << c << '\n';
            cout.flush();
            int res;
            cin >> res;
            return res;
        };

        vector<tup> impv, crwv;
        vector<int> ans;
        for (int i = 1; i < n; i += 3) {
            int res = query(i, i + 1, i + 2);
            if (res == -1) return 0;

            if (res == 0) {
                impv.push_back({i, i + 1, i + 2});
            } else {
                crwv.push_back({i, i + 1, i + 2});
            }
        }

        int imp, crw;
        auto &x = impv[0];
        auto &y = crwv[0];
        int res = query(x.a[0], x.a[1], y.a[0]) +
                  query(x.a[0], x.a[1], y.a[1]);
        if (res == 0) {  // 0 and 1 is imp
            imp = x.a[0];
        } else {  // one of 0 or 1 is imp
            imp = x.a[2];
        }
        res = query(y.a[0], y.a[1], imp);
        if (res == 1) {
            crw = y.a[0];
        } else {
            crw = y.a[2];
        }

        for (auto &x : impv) {
            int res1 = query(x.a[0], x.a[1], crw);
            int res2 = query(x.a[0], x.a[2], crw);
            if (res1 == 1) {  // one of 0 or 1 is crew
                if (res2 == 1) {
                    ans.push_back(x.a[1]);
                } else {
                    ans.push_back(x.a[0]);
                }
                ans.push_back(x.a[2]);
            } else {
                ans.push_back(x.a[0]);
                ans.push_back(x.a[1]);
                if (res2 == 0) {
                    ans.push_back(x.a[2]);
                }
            }
        }

        for (auto &x : crwv) {
            int res1 = query(x.a[0], x.a[1], imp);
            int res2 = query(x.a[0], x.a[2], imp);
            if (res1 == 0) {  // one of 0 or 1 is imp
                if (res2 == 0) {
                    ans.push_back(x.a[0]);
                } else {
                    ans.push_back(x.a[1]);
                }
            } else if (res2 == 0) {
                ans.push_back(x.a[2]);
            }
        }

        cout << "! " << ans.size() << ' ';
        for (auto &x : ans) cout << x << ' ';
        cout << '\n';
        cout.flush();
    }
    return 0;
}