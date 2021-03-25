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

    int aux = INF;
    FOR(i, 0, 3) {
        int n; cin >> n;
        aux = min(aux, n);
    }
    int b = aux; aux = INF;
    FOR(i, 0, 2) {
        int n; cin >> n;
        aux = min(aux, n);
    }
    cout << b + aux - 50 << "\n";
    return 0;
}