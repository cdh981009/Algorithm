#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> getPi(const string& p) {
    int m = p.size();
    vector<int> pi(m, 0);

    int match = 0;
    // i: 현재까지 본 t의 index
    // match: 현재까지 매칭된 길이 (p[0...match])
    FOR(i, 1, m) {
        // 현재 t[i-match]를 시작으로 match개 만큼 확인중
        // 그 전까지는 t[i-match...i-1] == p[0...match-1]
        while (match > 0 && p[i] != p[match])
            match = pi[match-1];

        if (p[i] == p[match])
            match++;
        // 다음 iteration에서 i가 증가하므로 i와 match가 각각 다음 글자를 확인하게 된다.

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
    // i: 현재까지 본 t의 index
    // match: 현재까지 매칭된 길이 (p[0...match])
    FOR(i, 0, n) {
        // 현재 t[i-match]를 시작으로 match개 만큼 확인중
        // 그 전까지는 t[i-match...i-1] == p[0...match-1]
        while (match > 0 && t[i] != p[match])
            match = pi[match-1];
        
        if (t[i] == p[match])
            match++;
        // 다음 iteration에서 i가 증가하므로 i와 match가 각각 다음 글자를 확인하게 된다.

        if (match == m) {
            ans.push_back(i-m+1);
            match = pi[match-1];
        }
    }
    return ans;    
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    constexpr int N = 360000;
    int n; cin >> n;
    string a(N, 0);
    string b(N, 0);
    FOR(i, 0, 2) {
        FOR(j, 0, n) {
            int x; cin >> x;
            if (i == 0)
                a[x] = 1;
            else
                b[x] = 1;
        }
    }

    if (!kmp(a + a, b).empty() && !kmp(b + b, a).empty())
        cout << "possible\n";
    else
        cout << "impossible\n";

    return 0;
}