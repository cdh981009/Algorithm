#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string str;
    cin >> n >> str;

    list<int> l;
    l.assign({0});
    auto it = l.begin();
    FOR(i, 0, n) {
        if (str[i] == 'R') it++;
        l.insert(it, i + 1);
        --it;
    }

    for (auto x : l) cout << x << ' ';
    cout << '\n';

    return 0;
}