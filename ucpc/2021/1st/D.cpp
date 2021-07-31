#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 301010;

using ll = long long;

ll ans;
int n;
string str;
int arr1[N];

int cnt = 0;
int arr2[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    cin >> str;
    FOR(i, 0, n) {
        cin >> arr1[i];
    }

    // refine
    bool prev = (str[0] == 'W');
    bool first = true;
    int mx = 0;
    FOR(i, 1, n) {
        bool curr = (str[i] == 'W');
        if (curr != prev) {
            if (first) {
                first = false;
            } else {
                arr2[cnt++] = mx;
            }
            mx = arr1[i];
        } else {
            mx = max(mx, arr1[i]);
        }
        prev = curr;
    }

    sort(arr2, arr2 + cnt);
    FOR(i, 0, (cnt + 1) / 2) {
        ans += arr2[cnt - 1 - i];
    }

    cout << ans << '\n';
    return 0;
}