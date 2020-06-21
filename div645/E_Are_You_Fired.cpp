#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int tail = n / 2;
    int head = n - tail;
    vector<int> arr(n, 0);
    long long sum = 0;
    FOR(i, 0, head) {
        int x; cin >> x;
        arr[i] = x;
        sum += x;
    }
    int x; cin >> x;
    FOR(i, 0, tail) {
        arr[i + head] = x;
        sum += x;
    }

    int ans = -1;
    long long minSum = sum;
    long long newVal = sum;
    int i = 0;
    for (int k = n; k >= head; --k, minSum -= x, newVal -= arr[i++]) {
        minSum = min<long long> (minSum, newVal);
        //cout << k << " " << minSum << endl;
        if (minSum > 0) {
            ans = k;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}