#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 2e5 + 10;

int ans[N];
int arr[N];
int cnt[N];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n;
        memset(cnt, 0, sizeof(int) * (n + 1));

        FOR(i, 0, n) {
            cin >> arr[i];
            cnt[arr[i]]++;
        }

        int s, i;
        s = i = m = 0;
        set<int> st;
        FOR_(i, 0, n + 1)
            st.insert(i);

        while (i < n) {
            st.erase(arr[i]);
            cnt[arr[i]]--;
            int x = *st.begin();
            if (cnt[x] == 0) {
                ans[m++] = x;
                FOR_(j, s, i)
                    st.insert(arr[j]);
                s = i + 1;
            }
            i++;
        }


        cout << m << '\n';

        FOR(i, 0, m)
            cout << ans[i] << ' ';

        cout << '\n';
    }
    return 0;
}