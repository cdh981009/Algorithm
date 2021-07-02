#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = unsigned long long;

const int N = 101010;

struct product {
    ll a, b;
    bool operator<(const product& o) {
        return this->b < o.b;
    }
} arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll sum = 0;
    FOR(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        arr[i].a = a;
        arr[i].b = b;
        sum += a;
    }
    sort(arr, arr + n);
    
    ll cnt = 0;
    ll add = 0;
    FOR(i, 0, n) {
        auto& p = arr[i];
        if (cnt < p.b) {
            add += min(p.b - cnt, sum - cnt);
            cnt = p.b;
        }

        cnt += p.a;
        if (cnt >= sum)
            break;
    }

    ll ans = sum + add;
    cout << ans << '\n';

    return 0;
}