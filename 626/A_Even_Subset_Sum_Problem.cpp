#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int even = -1;
        vector<int> odd;
        FOR(i, 0, n) {
            int num; cin >> num;
            if (num % 2 == 0)
                even = i + 1;
            else if (odd.size() < 2)
                odd.push_back(i + 1);
        }
        if (even == -1 && odd.size() < 2)
            cout << "-1\n";
        else if (even != -1)
            cout << 1 << "\n" << even << "\n";
        else
            cout << 2 << "\n" << odd[0] << " " << odd[1] << "\n";
    }
    return 0;
}