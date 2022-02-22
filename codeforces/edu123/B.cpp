#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 60;
constexpr int M = 1e9 + 7;

bool printed[N];
int n;
int cnt = 0;

void print(int i, int p, int pp, vector<int>& v) {
    if (cnt >= n) return;

    if (i == n) {
        FOR(i, 0, v.size()) {
            cout << v[i] << ' ';
        }
        cout << '\n';
        cnt++;
    }

    FOR_(x, 1, n) {
        if (printed[x] == false && p + pp != x) {
            v.push_back(x);
            printed[x] = true;
            print(i + 1, x, p, v);
            v.pop_back();
            printed[x] = false;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        cnt = 0;
        vector<int> v;
        print(0, 0, 0, v);
    }

    return 0;
}