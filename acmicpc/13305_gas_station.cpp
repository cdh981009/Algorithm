// 11305: 주유소
// https://www.acmicpc.net/problem/11305
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 101010;

long long dist[N];
long long cost[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long totalCost = 0;

    int n; cin >> n;
    FOR(i, 0, n - 1) {
        cin >> dist[i];
    }
    FOR(i, 0, n) {
        cin >> cost[i];
    }

    long long minPrice = INT32_MAX;

    FOR(i, 0, n - 1) {
        minPrice = min<long long>(minPrice, cost[i]);
        totalCost += dist[i] * minPrice;
    }

    cout << totalCost << '\n';

    return 0;
}