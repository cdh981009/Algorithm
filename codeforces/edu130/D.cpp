#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rep_(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define printYN(pos) cout << (pos ? "YES" : "NO") << '\n'
#define printPOS(pos) cout << (pos ? "POSSIBLE" : "IMPOSSIBLE") << '\n'

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpii = vector<pii>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 101010;
constexpr int M = 100;

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<int> str(n, -1);

    auto op1 = [](int i) {
        cout << "? 1 " << i + 1 << '\n';
        cout.flush();
        char x; cin >> x;
        return x;
    };

    auto op2 = [](int l, int r) {
        cout << "? 2 " << l + 1 << ' ' << r + 1 << '\n';
        cout.flush();
        int x; cin >> x;
        return x;
    };

    int prev = 0, x;
    // get initial values
    FOR(i, 0, n) {
        if (i == 0) {
            str[i] = op1(i);
            prev = 1;
        } else {
            x = op2(0, i);
            if (x != prev) {
                str[i] = op1(i);
            }
            prev = x;
        }
    }

    // do binary search
    int hi, lo, mid;

    FOR(i, 0, n) {
        if (str[i] != -1) continue;

        vector<bool> cnt(26, false);
        vector<int> ind;

        int j = i - 1;
        while (j >= 0) {
            int x = str[j] - 'a';
            if (!cnt[x]) {
                cnt[x] = true;
                ind.push_back(j);
            }
            j--;
        }

        lo = 0;
        hi = ind.size() - 1;

        while (true) {
            if (hi == lo) {
                str[i] = str[ind[lo]];
                break;
            }

            mid = (hi + lo) / 2;
            int x = op2(ind[mid], i);

            if (x == mid + 1) { // in range [lo..mid]
                hi = mid;
            } else { // in range [mid + 1.. hi]
                lo = mid + 1;
            }
        }
    }

    cout << "! ";
    FOR(i, 0, n) {
        cout << (char)str[i];
    }

    cout.flush();

    return 0;
}