#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e5;

string str;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> str;
        int n = str.size();
        bool pos = false;
        FOR(i, 0, n) {
            if (str[i] != 'a') {
                pos = true;
                break;
            }
        }
        if (pos) {
            cout << "YES\n";
            int ind;
            FOR(i, 0, n) {
                if (str[str.size() - 1 - i] != 'a') {
                    ind = i;
                    break;
                }
            }
            FOR(i, 0, n) {
                if (i == ind)
                    cout << 'a';
                cout << str[i];
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}