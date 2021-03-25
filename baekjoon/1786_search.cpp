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

vector<int> kmp(const string& t, const string& p) {
    int n = t.size();
    int m = p.size();
    vector<int> pi = getPi(p);

    vector<int> ans;
    int begin = 0, match = 0;
    while (begin <= n - m) {
        if (match < m && t[begin + match] == p[match]) {
            ++match;
            if (match == m)
                ans.push_back(begin);
        } else {
            if (match == 0) {
                ++begin;
            } else {
                // p[0...match-1] == t[begin...match-1];
                // pi[match-1] : p[0...match-1]의 접두사도 되고 접미사도 되는 최대 길이
                begin += match - pi[match - 1];
                match = pi[match - 1];
            }
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
        cout << i+1 << " ";
    }
    cout << "\n";

    return 0;
}