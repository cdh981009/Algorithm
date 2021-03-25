#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int n;
vector<int> arr(N + 1);
vector<int> w(N + 1);

void post2pre(int s, int e) {
    // [s, e)
    if (s >= e)
        return;
    int p = arr[e-1];
    cout << p << " ";
    int r = s-1;
    for (int step = e - s; step > 0; step /= 2) {
        while (r + step < e && w[arr[r + step]] < w[p])
            r += step;
    }
    r++;
    post2pre(s, r);
    post2pre(r, e-1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    // inorder
    FOR(i, 0, n) {
        int x; cin >> x;
        w[x] = i;
    }
    // postorder
    FOR(i, 0, n) {
        int x; cin >> x;
        arr[i] = x;
    }
    post2pre(0, n);
    return 0;
}