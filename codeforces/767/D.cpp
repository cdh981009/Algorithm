#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5;

int ans;
string str[N];
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
        cin >> n;
        bool pos = false;
        FOR(i, 0, n) {
            cin >> str[i];
            if (str[i].size() == 1)
                pos = true;
            if (str[i].size() == 2 && str[i][0] == str[i][1])
                pos = true;
            if (str[i].size() == 3 && str[i][0] == str[i][2])
                pos = true;
        }

        if (!pos) {
            set<string> st;
            FOR(i, 0, n) {
                string c = str[i];
                reverse(c.begin(), c.end());
                if (i != 0) {
                    if (c.size() == 2) {
                        auto it = st.lower_bound(c);
                        if (it != st.end() && (*it)[0] == c[0] && (*it)[1] == c[1]) {
                            pos = true;
                            break;
                        }
                    } else {  // 3
                        auto it = st.lower_bound(c);
                        if (it != st.end() && (*it) == c) {
                            pos = true;
                        }
                        c.pop_back();
                        it = st.lower_bound(c);
                        if (it != st.end() && (*it) == c) {
                            pos = true;
                        }
                    }
                }
                st.insert(str[i]);
            }
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}