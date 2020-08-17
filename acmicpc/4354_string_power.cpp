#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> getPi(const string& p) {
    int m = p.size();
    vector<int> pi(m, 0);
    int begin = 1, match = 0;
    while (begin + match < m) {
        if (p[begin + match] == p[match]) {
            ++match;
            pi[begin + match - 1] = match;
        } else {
            if (match == 0) {
                ++begin;
            } else {
                begin += match - pi[match - 1];
                match = pi[match - 1];
            }
        }
    }
    return pi;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string p;
    while (cin >> p, p != ".") {
        auto v = getPi(p);
        int l = p.size();
        int x = v.back();
        int ans = 1;
        if (l % (l - x) == 0)
            ans = l / (l - x);
        cout << ans << "\n";
    }

    return 0;
}