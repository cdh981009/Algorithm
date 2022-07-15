#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 7)
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
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using mii = map<int, int>;
using mll = map<ll, ll>;

constexpr int N = 202520;
constexpr int M = 450;

ll n, m, k, q, ans;
ll a[N];
bool arr[N];
bool all0[M];
bool all1[M];

void prop(int bi) {
    int s = bi * M;
    int e = min(N, (bi + 1) * M);

    if (all0[bi]) {
        rep(i, s, e) arr[i] = 0;
    } else if (all1[bi]) {
        rep(i, s, e) arr[i] = 1;
    }
}

void udt(int bi) {
    int s = bi * M;
    int e = min(N, (bi + 1) * M);

    bool& a0 = all0[bi];
    bool& a1 = all1[bi];
    a0 = a1 = true;
    rep(i, s, e) {
        if (arr[i] == 1) a0 = false;
        if (arr[i] == 0) a1 = false;
    }
}

void sub(ll x) {
    int bi = x / M;
    int s = bi * M;
    int e = min(N, (bi + 1) * M);

    prop(bi);

    bool b = true;
    rep(i, x, e) {
        if (arr[i] == 1) {
            arr[i] = 0;
            b = false;
            break;
        } else {
            arr[i] = 1;
        }
    }

    udt(bi);

    if (b) {
        rep(i, bi + 1, M) {
            if (all0[i]) {
                all1[i] = true;
                all0[i] = false;
            } else {
                prop(i);

                int s = i * M;
                int e = min(N, (i + 1) * M);

                rep(j, s, e) {
                    if (arr[j] == 1) {
                        arr[j] = 0;
                        break;
                    } else {
                        arr[j] = 1;
                    }
                }

                udt(i);

                break;
            }
        }
    }
}

void add(ll x) {
    int bi = x / M;
    int s = bi * M;
    int e = min(N, (bi + 1) * M);

    prop(bi);

    bool c = true;
    rep(i, x, e) {
        if (arr[i] == 0) {
            arr[i] = 1;
            c = false;
            break;
        } else if (c) {
            c = true;
            arr[i] = 0;
        }
    }

    udt(bi);

    if (c) {
        rep(i, bi + 1, M) {
            if (all1[i]) {
                all0[i] = true;
                all1[i] = false;
            } else {
                prop(i);

                int s = i * M;
                int e = min(N, (i + 1) * M);

                rep(j, s, e) {
                    if (arr[j] == 0) {
                        arr[j] = 1;
                        break;
                    } else {
                        arr[j] = 0;
                    }
                }

                udt(i);

                break;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    rep(i, 0, M) all0[i] = true;

    cin >> n >> q;

    rep(i, 0, n) {
        cin >> a[i];
        add(a[i]);
    }

    rep(i, 0, q) {
        int k, l;
        cin >> k >> l;
        k--;
        ll bf = a[k];
        a[k] = l;
        sub(bf);
        add(l);

        for (int j = M - 1; j >= 0; --j) {
            if (!all0[j]) {
                prop(j);
                int s = j * M;
                int e = min(N, (j + 1) * M);
                for (int k = e - 1; k >= s; --k) {
                    if (arr[k] == 1) {
                        cout << k << '\n';
                        break;
                    }
                }
                break;
            }
        }
    }

    return 0;
}