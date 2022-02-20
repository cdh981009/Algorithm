#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 201010;

int ans;
int arr[N];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) cin >> arr[i];

    vector<pii> v;

    FOR(i, 0, n) {
        if (v.empty()) {
            v.push_back({arr[i], 1});
        } else {
            if (v.back().first == arr[i]) {
                int cnt = v.back().second;
                if (cnt + 1 == arr[i]) {
                    while (cnt--) {
                        v.pop_back();
                    }
                } else {
                    v.emplace_back(arr[i], cnt + 1);
                }
            } else {
                v.emplace_back(arr[i], 1);
            }
        }

        cout << v.size() << '\n';
    }
    return 0;
}