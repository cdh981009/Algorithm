// 3033
// https://www.acmicpc.net/problem/3033
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
constexpr int M = 100003;
int n;
string str;


// 라빈-카프 교훈:
// 1. hash를 어떤 이유로 약하게 한다면 hash가 우연히 맞은 것 인지 직접 확인 해야 하고, (시간복잡도 저격 당하기 가능)
// 2. 그게 꺼림칙하다면 hash를 두개 이상으로 해서 ((h1 << 31) | h2) 한것을 key로 쓰자!

bool rabinKarp(int len) {
    vector<vector<int>> hs(M, vector<int>());

    ll h = 0, m = M, b = 2, p = 1;

    FOR(i, 0, len) {
        h = ((h * b) % m + str[i]) % m;
        p = (p * b) % m;
    }

    FOR(i, 0, n - len + 1) {
        if (i != 0) {
            h = ((h * b) % m - (p * str[i - 1]) % m + m) % m;
            h = (h + str[i + len - 1]) % m;
        }
        if (!hs[h].empty()) {
            for (auto x : hs[h]) {
                int cnt = 0;
                FOR(j, 0, len) {
                    if (str[x + j] != str[i + j]) {
                        break;
                    }
                    cnt++;
                }
                if (cnt == len)
                    return true;
            }
        }
        hs[h].push_back(i);
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> str;

    int x = 0;
    for (int step = n; step >= 1; step >>= 1)
        while (x + step < n && rabinKarp(x + step))
            x += step;

    cout << x << '\n';

    return 0;
}