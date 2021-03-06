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

    int len; cin >> len;
    vector<bool> ans1(len);
    vector<bool> ans2(len);
    FOR(i, 0, len*2) {
        int x; cin >> x;
        if (i < len)
            ans1[i] = x;
        else
            ans2[i - len] = x; 
    }
    int a, b;
    a = b = 0;
    FOR(i, 0, len) {
        a += ans1[i] & !ans2[i];
        b += ans2[i] & !ans1[i];
    }
    cout << (a == 0 ? -1 : max(1, b/a + 1)) << endl;
    return 0;
}