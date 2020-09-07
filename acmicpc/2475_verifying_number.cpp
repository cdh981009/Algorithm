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

    int num = 0;
    FOR(i, 0, 5) {
        int x; cin >> x;
        x = x * x;
        num += x;
    } 
    cout << (num % 10) << "\n";
    return 0;
}