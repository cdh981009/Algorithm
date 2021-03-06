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

    int n; cin >> n;
    vector<int> nums(n);
    FOR(i, 0, n) {
        int x; cin >> x;
        nums[i] = x;
    }

    int res = 0;
    int carry = 0;
    FOR(i, 0, 30) {
        int mask = ~(~0<<(i+1));
        sort(nums.begin(), nums.end(), [mask](int l, int r) -> bool { return (l&mask) < (r&mask); });
        int oneCnt = 0;
        for (auto x : nums) {
            oneCnt += ((x>>i)&1);
        }
        res = (n % 2 == 0 && oneCnt % 2 == 1) ? (res|(1<<i)) : res;
        res = (carry % 2 == 1) ? (res^(1<<i)) : res;
        carry = 0;
        FOR(j, 0, n - 1) {
            if ((nums[j]&mask) == 0) continue;
            auto it = lower_bound(nums.begin() + j + 1, nums.end(), mask+1-(nums[j]&mask), [mask](int l, int v) -> bool { return (l&mask) < v; });
            carry ^= ((nums.end() - it) % 2 == 1);
        }
    }
    cout << res << "\n";
    return 0;
}