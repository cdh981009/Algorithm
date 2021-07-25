#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n; cin >> n;
        vector<char> vec;
        vector<char> srt;
        FOR(i, 0, n) {
            char c; cin >> c;
            vec.push_back(c);
        }
        srt = vec;
        sort(srt.begin(), srt.end());
        int k = 0;
        FOR(i, 0, n) {
            if (srt[i] != vec[i])
                k++;
        }
        cout << k << '\n';
    }
    return 0;
}