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

constexpr int N = 101010;
constexpr int M = 100;

string str;
int q;
ll t[N], k[N];

struct Query {
    ll t, k, i;

    bool operator<(const Query& o) {
        return this->t < o.t;
    }
} qs[N];

int trans[3][2] = {
    {1, 2},
    {2, 0},
    {0, 1}
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str >> q;
    FOR(i, 0, q) {
        cin >> t[i] >> k[i];
        k[i]--;
        qs[i] = {t[i], k[i], i};
    }

    sort(qs, qs + q);


    FOR(i, 0, q) {
        ll ct = t[i];
        ll ck = k[i];

        ll j = 0;
        while (ct > 0 && (ck >> j) > 0) {
            ct--;
            j++;
        }

        ll ind;
        int curr;
        ind = (ck >> j);
        curr = str[ind] - 'A';

        if (ct != 0) {
            int rem = ct % 3;
            curr += rem;
            curr %= 3;
        }

        while (j > 0) {
            j--;
            curr = trans[curr][(ck >> j) % 2];
        }

        cout << (char)(curr + 'A') << '\n';
    }

    
    return 0;
}