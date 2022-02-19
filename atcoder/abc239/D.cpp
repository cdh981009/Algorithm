#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
ll n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    bool p[300] = {0,};
    FOR(i, 0, 300) {
        p[i] = true;
    }
    p[0] = p[1] = false;
    FOR(i, 0, 300) {
        if (p[i] == false) continue;
        for (int j = i * i; j < 300; j += i) {
            p[j] = false;
        }
    }

    bool pos = true;
    FOR_(i, a, b) {
        bool non = true;
        FOR_(j, c, d) {
            if (p[i + j]) {
                non = false;
                break;
            }
        }
        if (non) {
            pos = false;
            break;
        }
    }

    cout << (pos ? "Aoki" : "Takahashi") << '\n';
    return 0;
}