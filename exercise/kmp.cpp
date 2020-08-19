#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> getPi(const string& p) {
    int m = p.size();
    vector<int> pi(m, 0);
    
    int match = 0;
    FOR(i, 1, m) {
        while (match > 0 && p[i] != p[match])
            match = pi[match-1];
        if (p[i] == p[match])
            ++match;
        pi[i] = match;
    }
    return pi;
}

vector<int> kmp(const string& t, const string& p) {
    int n = t.size();
    int m = p.size();
    vector<int> pi = getPi(p);

    vector<int> ans;
    int match = 0;
    FOR(i, 0, m) {
        while (match > 0 && t[i] != p[match])
            match = pi[match - 1];
        if (t[i] == p[match])
            ++match;
        if (match == m) {
            ans.push_back(i - m + 1);
            match = pi[match - 1];
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    auto ans = kmp(t, p);
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";

    return 0;
}