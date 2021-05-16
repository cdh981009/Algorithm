#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 13;
constexpr int M = 1e9 + 7;

using ll = long long;
ll ans;
int n;
int arr[N];
map<vector<int>, ll> dp;

ll getDp(vector<int> state) {
    vector<int> unused;
    vector<int> visible;

    FOR(i, 0, n) {
        if (state[i] == 0) {
            unused.push_back(i);
        } else if (state[i] == 1) {
            visible.push_back(i);
        }
    }

    if (unused.empty())
        return 1;

    if (dp.count(state) == 1) {
        return dp[state];
    }

    ll& ref = dp[state];
    ref = 0;

    int used = n - unused.size();
    // arr[used] 에 맞게 하나를 더 고른다
    int i = 0;
    int j = 0;
    int v = visible.size() + 1;
    while (i < unused.size()) {
        int pick = unused[i];
        while (j < visible.size() && visible[j] < pick) {
            v--;
            state[visible[j]] = 2;
            j++;
        }
        state[pick] = 1;
        if (v == arr[used]) {
            ref += getDp(state);
        }
        state[pick] = 0;
        i++;
    }

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        dp.clear();
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
        }

        ans = getDp(vector<int>(n, 0));

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}