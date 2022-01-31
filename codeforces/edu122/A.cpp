#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        string n;
        cin >> n;
        string x;
        int ch = 4;
        for (int i = 7; i <= 999; i += 7) {
            string s = to_string(i);
            if (s.size() != n.size()) continue;
            int c = 0;
            for (int j = 0; j < n.size(); ++j) {
                if (s[j] != n[j])
                    c++;
            }
            if (c < ch) {
                ch = c;
                x = s;
            }
        }

        cout << x << '\n';
        
    }
    return 0;
}