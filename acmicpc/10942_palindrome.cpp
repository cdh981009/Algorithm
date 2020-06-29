#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n;
bool check[2000][2000];
bool dp[2000][2000];
vector<int> arr;

bool palindrome(int s, int e) {
    if (s == e)
        return true;
    if (s + 1 == e)
        return arr[s] == arr[e];
    bool& ref = dp[s][e];
    if (check[s][e])
        return ref;
    check[s][e] = true;
    if (arr[s] != arr[e])
        return ref = false;
    return ref = palindrome(s + 1, e - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(check, 0, sizeof(bool)*2000*2000);

    cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        arr.push_back(x);
    }
    int m; cin >> m;
    FOR(i, 0, m) {
        int s, e; cin >> s >> e;
        cout << palindrome(s-1, e-1) << "\n";
    }
    return 0;
}