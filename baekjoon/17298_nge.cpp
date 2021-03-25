// 17298: 오큰수
// https://www.acmicpc.net/problem/17298
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e6;
int arr[N];
int nge[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(nge, -1, sizeof(int) * N);

    int n; cin >> n;

    FOR(i, 0, n) {
        cin >> arr[i];
    }

    vector<pair<int, int>> stck;

    FOR(i, 0, n) {
        while (!stck.empty() && stck.back().first < arr[i]) {
            nge[stck.back().second] = arr[i];
            stck.pop_back();
        }
        stck.push_back({arr[i], i});
    }

    FOR(i, 0, n) {
        cout << nge[i] << ' ';
    }
    cout << '\n';

    return 0;
}