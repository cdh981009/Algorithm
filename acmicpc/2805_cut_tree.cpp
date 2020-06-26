#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n, m;

bool validCut(long long height, const vector<int>& trees) {
    long long get = 0;
    FOR(i, 0, trees.size())
        if (height <= trees[i])
            get += trees[i] - height;
    return get >= m;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<int> trees(n);
    FOR(i, 0, n) {
        int x; cin >> x;
        trees[i] = x;
    }

    int maximum = 1000000000;
    int h = 0;
    for (int step = maximum; step > 0; step /= 2) {
        while (h + step <= maximum && validCut(h + step, trees))
            h += step;
    }
    cout << h << endl;
    return 0;
}