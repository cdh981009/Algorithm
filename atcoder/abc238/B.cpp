#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 361;

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
    arr[0] = 0;
    FOR(i, 1, n + 1) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        arr[i] %= 360;
    }
    vector<int> vec;
    FOR_(i, 0, n) {
        vec.push_back(arr[i]);
    }
    vec.push_back(360);
    sort(vec.begin(), vec.end());
    int sz = 0;
    FOR(i, 1, vec.size()) {
        int s = vec[i] - vec[i - 1];
        if (s > sz)
            sz = s;
    }
    cout << sz << '\n';
    return 0;
}