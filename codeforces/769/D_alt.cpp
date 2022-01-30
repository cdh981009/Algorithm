#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;

int ans[N];
int arr[N];
int n;
int sn;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    vector<pii> segs;
    int a = 0;
    FOR(i, 0, n) {
        vector<pii> nseg;

        if (arr[i] == 1) {
            a++;
        } else {
            bool b = false;
            int s, e;
            s = e = 1;
            nseg.push_back({arr[i], 1});

            for (auto& p : segs) {
                int g = gcd(p.first, arr[i]);
                e += p.second;
                if (g == nseg.back().first) {
                    nseg.back().second += p.second;
                } else {
                    s += nseg.back().second; 
                    nseg.push_back({g, p.second});
                }
                if (g >= s && g <= e) {
                    b = true;
                    break;
                }
            }

            if (b) {
                a++;
                nseg.clear();
            }
        }

        ans[i] = a;
        swap(segs, nseg);
    }

    FOR(i, 0, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}