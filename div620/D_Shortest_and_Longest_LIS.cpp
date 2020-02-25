#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int len; cin >> len;
        char str[(int)2e5];
        cin >> str;
        int lessThan = 0;
        FOR(i, 0, len - 1)
            if (str[i] == '>')     
                lessThan++;
        int start = lessThan + 1;
        vector<int> base(len, -1);
        base[0] = start--;
        FOR(i, 0, len - 1)
            if (str[i] == '>')
                base[i + 1] = start--;
                
        // min LIS
        vector<int> lis(base.size());
        for (int i = 0, j = len; i < base.size(); /* */) {
            if (base[i] == -1) {
                int k = i;
                while (base[++k] == -1) {/* */}
                for (int l = k - 1; l >= i; --l) {
                    lis[l] = j--;
                }
                i = k;
            } else {
                lis[i] = base[i];
                ++i;
            }
        }
        for (auto n : lis)
            cout << n << " ";
        cout << "\n";

        // max LIS
        for (int i = 0, j = lessThan + 2; i < base.size(); ++i) {
            lis[i] = (base[i] == -1) ? j++ : base[i];
        }
        for (auto n : lis)
            cout << n << " ";
        cout << "\n";
    }
    return 0;
}