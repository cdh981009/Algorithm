// 1017: 소수 쌍
// https://www.acmicpc.net/problem/1017
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;

bool prime[2 * N + 1];

int n;

vector<int> even, odd;
vector<int> edges[N + 1];
bool visited[N + 1];
int eMatch[N + 1];
int oMatch[N + 1];
bool fix[N + 1];

vector<int> ans;

// ignore fixed numbers
bool dfs(int e) {
    if (visited[e] || fix[e])
        return false;
    visited[e] = true;

    for (auto o : edges[e]) {
        if (!fix[o] && (oMatch[o] == 0 || dfs(oMatch[o]))) {
            eMatch[e] = o;
            oMatch[o] = e;
            return true;
        }
    }
    return false;
}

int bipartiteMatch() {
    int match = 0;
    for (auto e : even) {
        memset(visited, 0, sizeof(bool) * (N + 1));
        match += (fix[e] || dfs(e));
    }
    return match;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // sieve
    FOR_(i, 0, 2 * N) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 2 * N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= 2 * N; j += i) {
                prime[j] = false;
            }
        }
    }

    // input
    int firstNum;
    cin >> n;
    FOR(i, 0, n) {
        int num;
        cin >> num;
        if (i == 0) {
            firstNum = num;
            fix[firstNum] = true;
        }

        if (num % 2 == 0)
            even.push_back(num);
        else
            odd.push_back(num);
    }

    // matching
    if (even.size() == odd.size()) {
        for (auto e : even)
            for (auto o : odd)
                if (prime[e + o])
                    edges[e].push_back(o);

        auto& other = ((firstNum % 2 == 0) ? odd : even);

        for (auto otherNum : other) {
            memset(eMatch, 0, sizeof(int) * (N + 1));
            memset(oMatch, 0, sizeof(int) * (N + 1));

            if (prime[otherNum + firstNum]) {
                fix[otherNum] = true;
                if (bipartiteMatch() == (n >> 1)) { // full match
                    ans.push_back(otherNum);
                }
                fix[otherNum] = false;
            }
        }

        sort(ans.begin(), ans.end());
    }

    // output
    if (ans.empty()) {
        cout << -1 << "\n";
    } else {
        for (auto a : ans)
            cout << a << " ";
        cout << "\n";
    }

    return 0;
}