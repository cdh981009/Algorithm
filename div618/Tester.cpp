#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int f(int x, int y) {
    return ((x | y) - y);
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> vec = {954336048, 315479581, 124252105, 880492165, 179952043 };
    
    cout << accumulate(vec.begin() + 1, vec.end(), vec[0], f);
    return 0;
}