#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 200;
int ans;
int n, k;
bool cnt[N];
vector<int> v;
vector<pair<int, int>> chords;
pair<int, int> aux[4];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        ans = 0;
        v.clear();
        chords.clear();
        memset(cnt, 0, sizeof(bool) * N);

        cin >> n >> k;
        FOR(i, 0, k) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cnt[x] = true;
            cnt[y] = true;
            chords.push_back({x, y});
        }

        FOR(i, 0, 2 * n) {
            if (!cnt[i]) {
                v.push_back(i);
            }
        }

        int s = v.size() / 2;
        FOR(i, 0, s) {
            chords.push_back({v[i], v[i + s]});
        }

        s = chords.size();
        FOR(i, 0, s) {
            FOR(j, i + 1, s) {
                auto& x = chords[i];
                auto& y = chords[j];

                aux[0] = {x.first, 0};
                aux[1] = {x.second, 0};
                aux[2] = {y.first, 1};
                aux[3] = {y.second, 1};

                sort(aux, aux + 4);
                if (!(aux[0].second == aux[1].second ||
                            aux[1].second == aux[2].second ||
                            aux[2].second == aux[3].second)) {
                                ans++;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}