#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int tc; cin >> tc;
    while (tc--) {
        int n, m; cin >> n >> m;
        FOR(i, 0, m) {
            int x, y; cin >> x >> y;
        }
        cout << n-1;
    }
}