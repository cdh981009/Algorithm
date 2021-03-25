// 5977: Mowing the Lawn
// https://www.acmicpc.net/problem/5977
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    priority_queue<pair<long long, int>> q;

    q.push({arr[0], 0});

    long long ans = arr[0];

    FOR(i, 1, n) {
        while (q.top().second < i - d) {
            q.pop();
        }
        long long m = q.top().first;
        long long x = max<long long>(0, m) + arr[i];
        q.push({x, i});
        
        ans = max<long long>(ans, x);
    }

    cout << ans << '\n';

    return 0;
}