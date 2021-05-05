#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 10010;
constexpr int M = 1e9 + 7;

int n;

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    long long p = 1;
    vector<int> ans;
    FOR(i, 1, n) {
        if (gcd(n, i) == 1) {
            p = (p * i) % n;
            ans.push_back(i);
        }
    }
    
    int skip = p == 1 ? 0 : p;
    cout << ans.size() - (p == 1 ? 0 : 1) << '\n';

    for (auto i : ans) {
        if (i == skip)
            continue;
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}