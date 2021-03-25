#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x[4], y[4];
    FOR(i, 0, 4)
        cin >> x[i] >> y[i];

    using pll = pair<long, long>;

    vector<pll> p(4);
    FOR(i, 0, 4) {
        p[i] = {x[i], y[i]};
    }

    auto op = [&p](int a, int b, int c) -> int {
        pll l = {p[b].first - p[a].first, p[b].second - p[a].second};
        pll r = {p[c].first - p[b].first, p[c].second - p[b].second};
        long long res = l.first * r.second - r.first * l.second;
        return (0 < res) - (res < 0);
    };
    int a = op(0, 1, 2) * op(0, 1, 3);
    int b = op(2, 3, 0) * op(2, 3, 1);

    bool cross;
    if (p[0] == p[2] ||
        p[0] == p[3] ||
        p[1] == p[2] ||
        p[1] == p[3]) { // 한 꼭짓점에서 만난다
            cross = true;
    } else if (a == 0 && b == 0) { // 일직선상에 있다
        vector<pll> aux(p);
        sort(aux.begin(), aux.end());
        if (aux[0] == p[0] || aux[0] == p[1])
            cross = (aux[1] != p[0] && aux[1] != p[1]);
        else
            cross = (aux[1] != p[2] && aux[1] != p[3]);
    } else { // 교차한다
        cross = (a <= 0 && b <= 0);
    }
    cout << cross << "\n";
    return 0;
}