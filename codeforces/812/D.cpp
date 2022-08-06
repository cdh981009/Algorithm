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

constexpr int N = 101010;
constexpr int M = 100;

vector<int> vec;
vector<int> aux;

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void ans(int a) {
    cout << "! " << a << '\n';
    cout.flush();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        n = (1 << n);

        vec.clear();
        aux.clear();

        rep(i, 0, n) vec.push_back(i + 1);

        while (vec.size() % 4 == 0) {
            aux.clear();

            for (int i = 0; i < vec.size(); i += 4) {
                int x = vec[i];
                int y;
                int res = ask(vec[i], vec[i + 2]);

                if (res == 0) { // 0 == 2
                    x = vec[i + 1]; // 1
                    y = vec[i + 3]; // 3
                } else if (res == 1) { // 0 > 2
                    x = vec[i];
                    y = vec[i + 3];
                } else { // 0 < 2
                    x = vec[i+1];
                    y = vec[i+2];
                }

                res = ask(x, y);
                if (res == 1) res = x;
                else res = y;

                aux.push_back(res);
            }

            swap(vec, aux);
        }

        if (vec.size() % 2 == 0) {
            int res = ask(vec[0], vec[1]);
            if (res == 1) res = vec[0];
            else res = vec[1];
            ans(res);
        } else {
            ans(vec[0]);
        }
    }

    return 0;
}