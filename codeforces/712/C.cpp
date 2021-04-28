#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5;

string s;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> s;
        string a, b;
        bool pos = true;
        if (s[0] != '1' || s[n - 1] != '1') {
            pos = false;
        } else {
            int cnt = 0;
            FOR(i, 0, n) {
                cnt += (s[i] == '1');
            }
            if (cnt % 2 == 1) {
                pos = false;
            } else {
                int one = 0;
                int zero = 0;
                FOR(i, 0, n) {
                    if (s[i] == '1') {
                        cnt--;
                        if (cnt == 0) {
                            a.push_back(')');
                            b.push_back(')');
                        } else if (one == 2) {
                            one = 1;
                            a.push_back(')');
                            b.push_back(')');
                        } else {
                            one += 1;
                            a.push_back('(');
                            b.push_back('(');
                        }
                    } else {
                        if (zero == 0) {
                            a.push_back('(');
                            b.push_back(')');
                            zero = 1;
                        } else {
                            a.push_back(')');
                            b.push_back('(');
                            zero = 0;
                        }
                    }
                }
            }
        }
        if (pos) {
            cout << "YES\n";
            cout << a << '\n';
            cout << b << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}