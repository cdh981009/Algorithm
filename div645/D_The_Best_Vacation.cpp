#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, days; cin >> n >> days;
    vector<int> months(2 * n, 0);
    FOR(i, 0, n) {
        int x; cin >> x;
        months[i] = months[i + n] = x;
    }

    long long ans = 0;
    long long hugs = 0;

    long long remain = days;
    for (auto start = months.begin(), end = months.begin(); start != months.end(); ++start) {
        while (end != months.end()) {
            if (end < start) {
                end = start;
            } else if (remain >= *end) {
                remain -= *end;
                hugs += (long long) *end * (*end + 1) / 2;
                end++;
            } else {
                break;
            }
        }
        long long addition = (end != months.end() ? remain * (remain + 1) / 2 : 0);

        // cout << *start << " " << *end << " " << hugs << " " << addition << " " << hugs + addition << endl;
        ans = max<long long>(ans, hugs + addition);
        if (start != end) {
            remain += *start;
            hugs -= (long long) *start * (*start + 1) / 2;
        }
    }

    hugs = 0;
    remain = days;
    for (auto start = months.rbegin(), end = months.rbegin(); start != months.rend(); ++start) {
        while (end != months.rend()) {
            if (end < start) {
                end = start;
            } else if (remain >= *end) {
                remain -= *end;
                hugs += (long long)*end * (*end + 1) / 2;
                end++;
            } else {
                break;
            }
        }
        long long addition = (end != months.rend()) ?
                (long long) *end * (*end + 1) / 2 - (*end - remain) * (*end - remain + 1) / 2
                : 0;
        // cout << *start << " " << hugs << " " << addition << " " << hugs+addition << endl;
        ans = max<long long>(ans, hugs + addition);
        if (start != end) {
            remain += *start;
            hugs -= (long long)*start * (*start + 1) / 2;
        }
    }

    cout << ans << "\n";
    return 0;
}