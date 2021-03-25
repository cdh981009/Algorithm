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

    int n, m; cin >> n >> m;
    vector<int> arr(n + 1 , 0);
    FOR(i, 0, n) {
        int x; cin >> x;
        arr[i + 1] = arr[i] + x;
    }
    FOR(i, 0, m) {
        int s, e; cin >> s >> e;
        cout << arr[e] - arr[s - 1] << "\n";
    }
    return 0;
}