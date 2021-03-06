// 8462: 배열의 힘
// https://www.acmicpc.net/problem/8462
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    using pii = pair<int, int>;
    vector<pair<pii, int>> queries(q);
    FOR(i, 0, q) {
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        queries[i] = {{s, e}, i};
    }

    int block = sqrt(n);
    sort(queries.begin(), queries.end(), [block](const pair<pii, int>& l, const pair<pii, int>& r) {
        const auto& x = l.first;
        const auto& y = r.first;
        return (x.second / block) != (y.second / block) ? (x.second / block) < (y.second / block) : x.first < y.first;
    });

    vector<int> cnt(1e6 + 1, 0);

    vector<long long> ansVec(q);
    int l = 0;
    int r = 0;
    long long ans = arr[0];
    cnt[arr[0]] = 1;

    // k * k * s
    // (k + 1) * (k + 1) * s = (k * k * s) + (2 * k + 1) * s
    // (k - 1) * (k - 1) * s = (k * k * s) - (2 * k - 1) * s

    auto add = [&](int ind) {
        // cnt[arr[ind]]++;
        ans += 1LL * (2 * cnt[arr[ind]]++ + 1) * arr[ind];
    };

    auto del = [&](int ind) {
        // cnt[arr[ind]]--;
        ans -= 1LL * (2 * cnt[arr[ind]]-- - 1) * arr[ind];
    };

    for (const auto& p : queries) {
        int s = p.first.first;
        int e = p.first.second;

        while (r < e)
            add(++r);
        while (r > e)
            del(r--);
        while (l < s)
            del(l++);
        while (l > s)
            add(--l);

        ansVec[p.second] = ans;
    }

    for (auto x : ansVec) {
        cout << x << '\n';
    }

    return 0;
}