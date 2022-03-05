#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;

constexpr int N = 1001010;
constexpr int M = 998244353;

ll pows[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    pows[0] = 1;
    FOR(i, 1, N) {
        pows[i] = (pows[i - 1] * 26) % M;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        ll cnt = 0;
        FOR_(i, 0, (n - 1) / 2) {
            int curr = str[i] - 'A';
            if (curr > 0) {
                // pick lower one
                ll rem = ((n - 1) / 2) - i;
                cnt += curr * pows[rem];
                cnt %= M;
            }
        }

        bool pal = true;
        for (int i = (n - 1) / 2; i >= 0; --i) {
            char o = str[n - 1 - i];
            if (str[i] < o) break;
            else if (str[i] > o) {
                pal = false;
                break;
            }
        }
        if (pal) {
            cnt++;
            cnt %= M;
        }

        cout << cnt << '\n';
    }

    return 0;
}