// 1644: Sum of Consecutive Prime Numbers
// https://www.acmicpc.net/problem/1644
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 1)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30;

int n, c;
int m;
int arr[N];

map<int, int> l, r;

vector<int> lv, rv;
vector<int> lCnt, rPreSum;

// 2 ^ 15 = 3e4
void getSum(int i, int e, int w, map<int, int>& m) {
    if (w >= INF)
        return;
    if (i == e) {
        m[w]++;;
    } else {
        getSum(i + 1, e, w, m);
        getSum(i + 1, e, w + arr[i], m);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    int m = n / 2;
    getSum(0, m, 0, l);
    getSum(m, n, 0, r);

    lv.reserve(l.size());
    lCnt.reserve(l.size());
    rv.reserve(r.size());
    rPreSum.reserve(r.size());

    for (auto& p : l) {
        lv.push_back(p.first);
        lCnt.push_back(p.second);
    }

    for (auto& p : r) {
        rv.push_back(p.first);
        rPreSum.push_back(p.second);
    }
    FOR(i, 1, rPreSum.size()) {
        rPreSum[i] += rPreSum[i - 1];
    }

    int cnt = 0;
    FOR(i, 0, lv.size()) {
        int c1 = lv[i];
        int c2 = c - c1;
        auto it = upper_bound(rv.begin(), rv.end(), c2);
        int ind = it - rv.begin() - 1;

        cnt += lCnt[i] * rPreSum[ind]; 
    }

    cout << cnt << '\n';

    return 0;
}