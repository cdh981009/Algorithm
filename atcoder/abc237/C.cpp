#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 100;

int ans;
int arr[N];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int i = 0;
    for (; i < str.size(); ++i) {
        if (str[i] != 'a') break;
    }
    int j = 0;
    for (; j < str.size(); ++j) {
        if (str[str.size() - j - 1] != 'a') break;
    }
    
    //cout << i << ' ' << j;
    bool pal = true;
    if (j < i) pal = false;
    FOR(k, 0, (int)str.size() - i - j) {
        if (str[i + k] != str[str.size() - j - k - 1])
            pal = false;
    }
    cout << (pal ? "Yes" : "No") << '\n';

    return 0;
}