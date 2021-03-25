// 1017: 소수 쌍
// https://www.acmicpc.net/problem/1017
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e3;
constexpr int M = 50;

bool prime[2 * N + 1];

int n;
int number[M];
bool visited[M];
int oMatch[M];

// ignore fixed numbers
bool dfs(int e) {
    if (visited[e])
        return false;
    visited[e] = true;

    FOR(i, 0, n) {
        if (prime[number[i] + number[e]] && (oMatch[i] == -1 || dfs(oMatch[i]))) {
            oMatch[i] = e;
            oMatch[e] = i;
            return true;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
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
        number[i] = num;
    }

    // matching
    vector<int> ans;
    FOR(i, 1, n) {
        if (prime[number[0] + number[i]]) {
            memset(oMatch, -1, sizeof(int) * (M));
            oMatch[0] = i;
            oMatch[i] = 0;

            int match = 1;
            FOR(j, 1, n) {
                if (number[j] % 2 == 1)
                    continue;
                memset(visited, 0, sizeof(bool) * (M));
                visited[0] = true;
                visited[i] = true;
                match += (dfs(j));
            }

            if (match == (n >> 1))
                ans.push_back(number[i]);
        }
    }

    sort(ans.begin(), ans.end());

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