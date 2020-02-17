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
    int base = ~0;
    while (len--) {
        int n; cin >> n;
        vec.push_back(n);
        base &= ~n;
    }
    int maxIndex = -INF;
    int maxVal = -INF;
    FOR(i, 0, vec.size()) {
        int newVal = base | vec[i] & vec[i];
        if (maxVal < newVal) {
            maxVal =  newVal;
            maxIndex = i;
        }
    }
    cout << vec[maxIndex] << " ";
    FOR(i, 0, vec.size()) {
        if (i == maxIndex) continue;
        cout << vec[i] << " ";
    }
    cout << "\n";
    return 0;
}