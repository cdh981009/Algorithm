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

constexpr int N = 201010;
constexpr int M = 100;

int n, m, k, q, ans;
int arr[N];

vector<char> v;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int preA = false;

    set<int> st;
    rep_(i, 1, 2 * n) {
        st.insert(i);
    }

    vpii arr;
    vpii req;
    vector<vector<pii>> chains(m);

    bool pos = true;
    int one = -1;

    rep(i, 0, m) {
        string str, dump;
        int x;
        cin >> str >> dump >> x;

        st.erase(x);

        if (i > 0 && preA == (str[0] == 'A')) {
            req.push_back({arr[i-1].second, i-1});
        }

        preA = (str[0] == 'A');

        arr.push_back({preA, x});

        if (x == 1) one = i;
    }

    if (one == -1) {
        pos = false;
    } else {
        sort(req.begin(), req.end());

        for (auto &[x, i] : req) {
            if (x == 1) continue;
            auto it = st.upper_bound(x);
            if (it == st.end()) {
                pos = false;
                break;
            }
            chains[i].push_back({1 - arr[i].first, *it});
            st.erase(it);
        }

        // put remaining in 1

        bool isA = arr[one].first;
        if (one == m - 1) {
            while (!st.empty()) {
                auto it = st.begin();
                chains[one].push_back({!isA, *it});
                isA = !isA;
                st.erase(it);
            }
        } else {
            if (arr[one].first == arr[one+1].first) {
                if (st.size() % 2 == 0) {
                    if (st.empty()) {
                        pos = false;
                    } else {
                        while (st.size() > 1) {
                            auto it = st.begin();
                            chains[one].push_back({!isA, *it});
                            isA = !isA;
                            st.erase(it);
                        }
                    }
                } else {
                    while (!st.empty()) {
                        auto it = st.begin();
                        chains[one].push_back({!isA, *it});
                        isA = !isA;
                        st.erase(it);
                    }
                }
            } else {
                if (st.size() % 2 == 1) {
                    while (st.size() > 1) {
                        auto it = st.begin();
                        chains[one].push_back({!isA, *it});
                        isA = !isA;
                        st.erase(it);
                    }
                } else {
                    while (!st.empty()) {
                        auto it = st.begin();
                        chains[one].push_back({!isA, *it});
                        isA = !isA;
                        st.erase(it);
                    }
                }
            }
        }

        if (!st.empty()) {
            if (*st.begin() > arr[m - 1].second) {
                chains[m - 1].push_back({1 - arr[m - 1].first, *st.begin()});
            } else {
                pos = false;
            }
        }
    }

    if (!pos) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        rep(i, 0, m) {
            cout << (arr[i].first ? 'A' : 'B') << " BLOCK " << arr[i].second << '\n';
            for (auto &[f, s] : chains[i]) {
                cout << (f ? 'A' : 'B') << " CHAIN " << s << '\n';
            }
        }
    }

    return 0;
}