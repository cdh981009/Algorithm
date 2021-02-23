#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int hp, n, m; cin >> hp >> n >> m;
        while (n > 0) {
            if (hp/2 + 10 < hp) {
                n--;
                hp = hp/2 + 10;
            } else {
                break;
            }
        }
        hp -= m * 10;
        cout << (hp <= 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}