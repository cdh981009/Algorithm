#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 10100;

int n, k;
int qor[N];
int qand[N];
int aor, aand;
int arr[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    
    int q = 2 * n;
    int res;
    
    FOR_(i, 2, n) {
        cout << "or 1 " << i << '\n';
        cout.flush();
        cin >> qor[i];
    }

    FOR_(i, 2, n) {
        cout << "and 1 " << i << '\n';
        cout.flush();
        cin >> qand[i];
    }

    cout << "or 2 3" << '\n';
    cout.flush();
    cin >> aor;

    cout << "and 2 3" << '\n';
    cout.flush();
    cin >> aand;

    int x = 0;
    FOR(i, 0, 31) {
        bool find = false;
        FOR_(j, 2, n) {
            bool o = (qor[j] & (1 << i));
            bool a = (qand[j] & (1 << i));
            if (!o && !a) {
                find = true;
            } else if (o && a) {
                x |= (1 << i);
                find = true;
            }
            if (find)
                break;
        }
        if (!find) {
            bool o = (aor & (1 << i));
            bool a = (aand & (1 << i));
            if (!o && !a) {
                x |= (1 << i);
            }
        }
    }

    // x is found
    arr[1] = x;
    // find others
    FOR_(i, 2, n) {
        int y = 0;
        FOR(j, 0, 31) {
            bool o = (qor[i] & (1 << j));
            bool a = (qand[i] & (1 << j));
            if (a) {
                y |= (1 << j);
            } else if (o) {
                if (!(x & (1 << j)))
                    y |= (1 << j);
            }
        }
        arr[i] = y;
    }

    sort(arr + 1, arr + n + 1);
    cout << "finish " << arr[k] << '\n';

    return 0;
}