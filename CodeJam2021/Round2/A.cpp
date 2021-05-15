#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 30;
constexpr int M = 50;

int ans;
int n;
int arr[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc >> n;
    FOR_(caseNum, 1, tc) {
        int x = 0;
        FOR(i, 1, 100) {
            cout << "M " << i << ' ' << 100 << endl;
            cin >> x;
            if (x == -1)
                break;
            if (i != x) {
                cout << "S " << i << ' ' << x << endl;
                cin >> x;
            }
        }
        if (x != -1) {
            cout << 'D' << endl;
            cin >> x;
            if (x != 1)
                break;
        } else {
            break;
        }
    }

    return 0;
}