#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 1e5;
int n;
int arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        set<int> s;
        FOR(i, 0, n) {
            s.insert(s.end(), i + 1);
            cin >> arr[i];
        }
        // 무조건 제일 큰 숫자가 아래 오는게 이득
        
        int x, y = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] == *(s.rbegin())) {
                x = i;
                while (x <= y) {
                    cout << arr[x] << ' ';
                    x++;
                }
                y = i - 1;
            }
            s.erase(arr[i]);
        }
        cout << '\n';
    }
    return 0;
}