#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int minFactor[1001];

void sieve() {
    FOR(i, 0, 1001)
        minFactor[i] = i;
    for (int i = 2; i * i <= 1000; ++i) {
        if (minFactor[i] != i) continue;
        for (int j = i * i; j <= 1000; j += i) {
            minFactor[j] = i;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        map<int, int> colors;
        vector<int> nums;
        while (n--) {
            int x; cin >> x;
            nums.push_back(x);
            if (colors.count(minFactor[x]) == 0)
                colors[minFactor[x]] = colors.size() + 1;
        }
        cout << colors.size() << "\n";
        for (auto i : nums)
            cout << colors[minFactor[i]] << " ";
        cout << "\n";
    }
    return 0;
}