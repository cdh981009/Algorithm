#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 20010;
constexpr int M = 50010;

using ll = long long;

int n, m;
int l[N];
vector<vector<int>> os;
vector<vector<int>> es;
vector<int> aux;
ll ans;

int main(int argc, char** argv) {
    int T, tc;
    
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n >> m;
        os.clear();
        es.clear();
        aux.clear();
        ans = 0;

        FOR(i, 0, n) {
            cin >> l[i];
            if (l[i] % 2 == 0)
                es.push_back(vector<int>());
            else
                os.push_back(vector<int>());
            FOR(j, 0, l[i]) {
                int w; cin >> w;
                if (l[i] % 2 == 0)
                    es.back().push_back(w);
                else
                    os.back().push_back(w);
            }
        }

        FOR(i, 0, es.size()) {
            auto& curr = es[i];
            sort(curr.begin(), curr.end());
        }
        FOR(i, 0, os.size()) {
            auto& curr = os[i];
            sort(curr.begin(), curr.end());
        }

        if (os.size() == 2 && es.size() != 0) { // special case
            aux.reserve(n);

            ll base = 0;
            FOR(i, 0, es.size()) {
                auto& curr = es[i];
                base += curr[0] + curr[1] + curr[2] + curr[3];
                aux.push_back(curr[2] + curr[3]);
            }
            sort(aux.rbegin(), aux.rend());
            FOR(i, 0, os.size()) {
                auto& curr = os[i];
                base += 2 * curr[0] + curr[1] + curr[2] + curr[3];
            }

            // case 1: odd at each end
            ll ans1 = base;
            FOR(i, 0, es.size()) {
                auto& curr = es[i];
                ans1 += curr[0] + curr[1];
            }
            FOR(i, 0, os.size()) {
                auto& curr = os[i];
                ans1 -= curr[2] + curr[3];
            }

            // case 2: odd at one end
            ll ans2 = base;
            ans2 -= aux[0];
            ans2 -= max(os[0][2] + os[0][3], os[1][2] + os[1][3]);

            // case 3: odd not in any end
            ll ans3 = base;
            if (es.size() >= 2) {
                ans3 -= aux[0] + aux[1];
            }

            ans = min(ans1, min(ans2, ans3));
        } else {
            aux.reserve(n);
            FOR(i, 0, es.size()) {
                auto& curr = es[i];
                ans += curr[0] + curr[1] + curr[2] + curr[3];
                aux.push_back(curr[2] + curr[3]);
            }
            FOR(i, 0, os.size()) {
                auto& curr = os[i];
                ans += 2 * curr[0] + curr[1] + curr[2] + curr[3];
                aux.push_back(curr[2] + curr[3]);
            }
            sort(aux.rbegin(), aux.rend());
            ans -= aux[0] + aux[1];
        }

        cout << "Case #" << tc + 1 << '\n';
        cout << ans << '\n';
    }

    return 0;
}