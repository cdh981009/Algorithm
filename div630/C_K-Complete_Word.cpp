#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        int m = n/k;
        int ans = 0;
        FOR(i, 0, (k+1)/2) {
            vector<int> cnt(27, 0);
            FOR(j, 0, m) {
                int l = i + k*j;
                int r = k*j + k - i - 1;
                cnt[str[l]-'a']++;
                cnt[str[r]-'a']++;
            }
            sort(cnt.begin(), cnt.end());
            int replace = 2*m - cnt.back();
            replace /= (i == k-i-1 ? 2 : 1);
            ans += replace;
        }
        cout << ans << "\n";
    }
    return 0;
}