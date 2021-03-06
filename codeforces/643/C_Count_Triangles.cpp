#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c, d; cin >> a >> b >> c >> d;
    long long sum = 0;
    for (long long x = a; x <= b; ++x) {
        long long minSum = x + b;
        long long maxSum = x + c;
        if (minSum <= c) {
            if (maxSum >= d) {
                sum += (d - c) * (d - c + 1) / 2;
                sum += (d - c + 1) * (maxSum - d);
            } else if (maxSum >= c) {
                sum += x * (x + 1) / 2;
            }
        } else if (minSum <= d) {
            if (maxSum >= d) {
                sum += (d - c) * (d - c + 1) / 2;
                sum -= (x + b - c - 1) * (x + b - c) / 2;
                sum += (d - c + 1) * (maxSum - d);
            } else {
                sum += x * (x + 1) / 2;
                sum -= (x + b - c - 1) * (x + b - c) / 2;
            }
        } else {
            sum += (d - c + 1) * (maxSum - minSum + 1);
        }
    }
    cout << sum << "\n";
    return 0;
}