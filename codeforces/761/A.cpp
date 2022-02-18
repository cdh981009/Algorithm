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
        string s, t;
        cin >> s >> t;
        vector<int> cnt(27, 0);
        FOR(i, 0, s.size()) {
            cnt[s[i] - 'a']++;
        }
        
        bool swp = false;
        if (t == "abc" && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) swp = true;
        sort(s.begin(), s.end());
        if (swp) {
            reverse(lower_bound(s.begin(), s.end(), 'b'), upper_bound(s.begin(), s.end(), 'c'));
        }

        cout << s << '\n';
    }
    return 0;
}