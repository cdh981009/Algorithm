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

    string str;
    while (cin >> str) {
        if (str == "0") break;
        bool b = true;
        FOR(i, 0, str.length() / 2) {
            if (str[i] != str[str.length() - 1 - i]) {
                b = false;
                break;     
            }
        }
        cout << (b ? "yes" : "no") << "\n";
    } 
    return 0;
}