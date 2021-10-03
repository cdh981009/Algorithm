#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int ans;
int arr[N], aux[N];
int n, x;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> x;
        FOR(i, 0, n) {
            cin >> arr[i];
            aux[i] = arr[i];
        }
        sort(aux, aux + n);
        bool p = true;
        int r = 0 + (x - 1);
        int l = n - 1 - (x - 1);
        r = min(n - 1, r);
        l = max(l, 0);
        FOR_(i, l, r) {
            if (aux[i] != arr[i]) {
                p = false;
                break;
            }
        }

        
        cout << (p ? "YES" : "NO") << '\n';
    }
    return 0;
}