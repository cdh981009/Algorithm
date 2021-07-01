#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using pii = pair<int, int>;
using ll = long long;

const int M = 1000000829;
string str;
map<int, int> mp;

int h(int x) {
    return (46759202LL * x + 190328584) % M;
}

int merge(int a, int b, char op) {
    if (op == '+') {
        return ((ll) a + b) % M;
    } else if (op == '*') {
        return ((ll) a * b) % M;
    } else { // '#'
        return (((285943LL * h(a) + 3825413LL) ^ 43897893) ^ ((568473LL * h(b) + 483722LL) ^ 3837485LL)) % M; 
    }
}

int parse(int s, int e) {
    if (isdigit(str[s])) {
        int a = str[s] - '0';
        s++;
        while (s <= e && isdigit(str[s])) {
            a = (((ll) a * 10) % M + (str[s] - '0')) % M;
            s++;
        }

        if (s > e)
            return a;
        
        int b = parse(s + 1, e);
        return merge(a, b, str[s]);
    } else {
        int i = s;
        int cnt = 1;
        while (cnt > 0) {
            i++;
            if (str[i] == '(')
                cnt++;
            if (str[i] == ')')
                cnt--;
        }
        int a = parse(s + 1, i - 1);
        if (i == e)
            return a;
        int b = parse(i + 2, e);
        return merge(a, b, str[i + 1]);
    }
}

void solve() {
    mp.clear();

    int n;
    cin >> n;
    FOR(i, 0, n) {
        cin >> str;
        int res = parse(0, str.length() - 1);
        if (mp.count(res) == 0) {
            mp[res] = mp.size() + 1;
        }
        cout << mp[res] << ' ';
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    FOR_(caseNum, 1, tc) {
        cout << "Case #" << caseNum << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}