#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    vector<int> vec;
    while (len--) {
        int n; cin >> n;
        vec.push_back(n);
    }
    sort(vec.rbegin(), vec.rend());
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}