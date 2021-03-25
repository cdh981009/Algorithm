// 11585: 속타는 저녁 메뉴
// https://www.acmicpc.net/problem/11585
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int gcd(int a, int b) {
    if (a > b)
        swap(a, b);

    while (a != 0) {
        b %= a;
        swap(a, b);
    }

    return b;
}

vector<int> getPi(const vector<char>& needle) {
    vector<int> pi(needle.size(), 0);

    int match = 0;
    FOR(i, 1, needle.size()) {
        while (match > 0 && needle[i] != needle[match]) {
            match = pi[match - 1];
        }

        if (needle[i] == needle[match]) {
            match++;
        }

        pi[i] = match;
    }

    return pi;
}

vector<int> kmp(const vector<char>& haystack, const vector<char>& needle) {
    auto pi = getPi(needle);

    vector<int> res;

    int match = 0;
    FOR(i, 0, haystack.size()) {
        while (match > 0 && haystack[i] != needle[match]) {
            match = pi[match - 1];
        }

        if (haystack[i] == needle[match]) {
            match++;
        }

        if (match == needle.size()) {
            res.push_back(i - match + 1);
            match = pi[match - 1];
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<char> str(2 * n);
    FOR(i, 0, n) {
        char c;
        cin >> c;
        str[i] = str[i + n] = c;
    }
    str.pop_back();

    vector<char> needle(n);
    FOR(i, 0, n) {
        char c;
        cin >> c;
        needle[i] = c;
    }

    auto res = kmp(str, needle).size();

    auto g = gcd(res, n);
    res /= g;
    n /= g;
    cout << res << '/' << n << '\n';

    return 0;
}