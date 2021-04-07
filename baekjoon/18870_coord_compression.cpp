// 18870: 좌표 압축
// https://www.acmicpc.net/problem/18870
#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 1e6;
int arr[N];
int sorted[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        arr[i] = sorted[i] = x;
    }
    sort(sorted, sorted + n);
    int nn = unique(sorted, sorted + n) - sorted;
    FOR(i, 0, n) {
        int pos = lower_bound(sorted, sorted + nn, arr[i]) - sorted;
        cout << pos << ' ';
    }
    cout << '\n';
    return 0;
}