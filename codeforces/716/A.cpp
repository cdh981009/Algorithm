#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10010;

bool isSqr[N];
int n;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i * i <= 10000; ++i) {
        isSqr[i * i] = true;
    }

    int tc;
    cin >> tc;

    while (tc--) {
        bool pos = false;
        
        cin >> n;
        
        FOR(i, 0, n) {
            int x;
            cin >> x;
            if (!isSqr[x]) {
                pos = true;
            }
        }

        cout << (pos ? "YES" : "NO");
        cout << '\n';
    }
    return 0;
}