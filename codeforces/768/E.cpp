#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;
int a[N];
pii ind[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    FOR_(i, 0, n)
    ind[i] = {-1, -1};

    FOR(i, 0, n) {
        cin >> a[i];
        if (ind[a[i]].first == -1)
            ind[a[i]].first = i;
        ind[a[i]].second = i;
    }
    vector<pii> segs;
    FOR_(i, 1, n) {
        if (ind[i].first != ind[i].second)
            segs.push_back(ind[i]);
    }
    sort(segs.begin(), segs.end());
    
    int s, e, ans;
    ans = 0;
    s = -1;
    e = -1;
    vector<int> stck;
    for (auto &[l, r] : segs) {

        if (e > r) continue;

        if (s == -1) {
            s = l;
        } else if (l > e) {
            ans += (e - s + 1) - (stck.size() + 1);
            s = l;
            stck.clear();
        }
        
        e = r;

        while (!stck.empty()) {
            int prev = stck.back();
            stck.pop_back();

            if (stck.empty()) {
                stck.push_back(prev);
                break;
            } else {
                if (stck.back() < l) {
                    stck.push_back(prev);
                    break;
                }
            }
        }
        stck.push_back(r);
    }
    ans += (e - s + 1) - (stck.size() + 1);

    cout << ans << '\n';

    return 0;
}