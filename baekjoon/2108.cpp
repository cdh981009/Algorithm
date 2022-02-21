#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    double sum = 0;
    vector<int> v(n);
    vector<int> cnt(8010, 0);
    FOR(i, 0, n) {
        int x; cin >> x;
        v[i] = x;
        sum += x;
        cnt[x + 4000]++;
    }

    vector<int> aux;
    int mx = 1;
    FOR(i, 0, 8010) {
        if (cnt[i] > mx) {
            aux.clear();
            aux.push_back(i);
            mx = cnt[i];
        } else if (cnt[i] == mx) {
            aux.push_back(i);
        }
    }

    sort(aux.begin(), aux.end());
    sort(v.begin(), v.end());

    sum /= n;
    cout << (int)round(sum) << '\n';
    cout <<  v[n / 2] << '\n';
    cout << (aux.size() > 1 ? aux[1] : aux[0]) - 4000 << '\n';
    cout << v.back() - v.front() << '\n';



    return 0;
}