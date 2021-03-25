// 2629: 양팔저울
// https://www.acmicpc.net/problem/2629
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30;
constexpr int W = 55000;
constexpr int BASE = 15000;

bool dp[W][N];
bool memoi[W][N];
int weight[N];

int n;

bool pick(int w, int i) {
    if (i == n) {
        return w == 0;
    }

    bool &ref = dp[w + BASE][i];
    bool &mem = memoi[w + BASE][i];
    
    if (mem) return ref;

    mem = true;
    return ref = (pick(w, i + 1) | pick(w - weight[i], i + 1) | pick(w + weight[i], i + 1));
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> weight[i];
    }
    int q; cin >> q;
    FOR(i, 0, q) {
        int x;
        cin >> x;
        cout << (pick(x, 0)? 'Y' : 'N') << ' ';
    }
    cout << '\n';

    return 0;
}