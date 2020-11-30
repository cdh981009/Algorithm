// 13548: 수열과 쿼리 6
// https://www.acmicpc.net/problem/13548
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

    // mo's algorithm
    // offline query
    // time complexiy is O((n + q) * sqrt(n))

    int n; cin >> n;
    vector<int> arr(n);
    FOR(i, 0, n) {
        int x; cin >> x;
        arr[i] = x;
    }

    int q; cin >> q;
    using pii = pair<int, int>;
    vector<pair<pii, int>> queries(q);
    FOR(i, 0, q) {
        int s, e; cin >> s >> e;
        s--;
        e--;
        queries[i] = {{s, e}, i};
    }

    int block = sqrt(n);
    sort(queries.begin(), queries.end(), [block](const pair<pii, int>& l, const pair<pii, int>& r) {
        const auto& x = l.first;
        const auto& y = r.first;
        return (x.second / block) != (y.second / block) ?
            (x.second / block) < (y.second / block) :
            x.first < y.first;
    });

    vector<int> numCnt(1e5 + 1, 0);
    vector<int> cntCnt(1e5 + 1, 0); // (what)
    vector<int> ansVec(q);
    int l = 0;
    int r = 0;
    numCnt[arr[0]] = 1;
    cntCnt[1] = 1;
    int ans = 1;

    // mom's spaghetti
    for (const auto& p : queries) {
        int s = p.first.first;
        int e = p.first.second;

        while (r < e) {
            r++;

            cntCnt[numCnt[arr[r]]]--;

            numCnt[arr[r]]++;

            cntCnt[numCnt[arr[r]]]++;
            if (numCnt[arr[r]] > ans) {
                ans = numCnt[arr[r]];
            }
        }

        while (r > e) {
            cntCnt[numCnt[arr[r]]]--;
            if (numCnt[arr[r]] == ans && cntCnt[numCnt[arr[r]]] == 0) {
                ans = numCnt[arr[r]] - 1;
            }

            numCnt[arr[r]]--;

            cntCnt[numCnt[arr[r]]]++;

            r--;
        }

        while (l < s) {
            cntCnt[numCnt[arr[l]]]--;
            if (numCnt[arr[l]] == ans && cntCnt[numCnt[arr[l]]] == 0) {
                ans = numCnt[arr[l]] - 1;
            }

            numCnt[arr[l]]--;

            cntCnt[numCnt[arr[l]]]++;

            l++;
        }

        while (l > s) {
            l--;

            cntCnt[numCnt[arr[l]]]--;
            
            numCnt[arr[l]]++;

            cntCnt[numCnt[arr[l]]]++;
            if (numCnt[arr[l]] > ans) {
                ans = numCnt[arr[l]];
            }
        }

        ansVec[p.second] = ans;
    }

    for (auto x : ansVec) {
        cout << x << '\n';
    }

    return 0;
}