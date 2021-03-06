#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // u = xor, v = sum
    long long u, v; cin >> u >> v;
    if (u > v || (v - u) % 2 == 1) {
        cout << -1 << endl;
    } else {
        long long n = (v - u) / 2;
        vector<long long> ans;
        if (n != 0) {
            ans.push_back(n);
            if ((n|u) == (n^u)) {
                ans.push_back(n|u);
            } else {
                ans.push_back(n);
                if (u != 0)
                    ans.push_back(u);
            }
        } else {
            if (u != 0)
                ans.push_back(u);
        }
    
        cout << ans.size() << "\n";
        if (ans.size() > 0) {
            for (auto i : ans)
                cout << i << " ";
            cout << "\n";
        }
    }
    
    return 0;
}