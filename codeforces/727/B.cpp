#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 101010;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    string str; cin >> str;
    FOR(i, 0, n) {
        arr[i + 1] = arr[i] + str[i] - 'a' + 1;
    }
    FOR(i, 0, q) {
        int l, r; cin >> l >> r;
        int ans = arr[r] - arr[l - 1];
        cout << ans << '\n';
    }

    return 0;
}