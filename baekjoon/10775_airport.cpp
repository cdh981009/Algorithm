#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
vector<int> root(N + 1);

int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    // 항상 루트가 그 셋에서 가장 작은 숫자여야 한다.
    if (x > y)
        swap(x, y);

    root[y] = x;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int g; cin >> g;
    FOR_(i, 0, g)
        root[i] = i;

    int ans = 0;
    bool isOpen = true;

    int p; cin >> p;
    FOR(i, 0, p) {
        int x; cin >> x;
        if (!isOpen)
            continue;
        // find(x) 는 1~x 까지 들어갈 수 있는 비행기에 대해
        // 현재 들어갈 수 있는 (비어있는) 가장 숫자가 큰 게이트를 의미한다.
        if (find(x) == 0)
            isOpen = false;
        else
            ans++, unite(x, find(x)-1);
    }
    cout << ans << "\n";
    
    return 0;
}