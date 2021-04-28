#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e5;

string a, b;
int n;
int pa[N];
int pb[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin >> n;
        cin >> a >> b;
        a.push_back('0');
        b.push_back('0');
        n += 1;
        
        pa[0] = a[0] == '1' ? +1 : -1;
        pb[0] = b[0] == '1' ? +1 : -1;
        FOR(i, 1, n) {
            pa[i] = pa[i - 1] + (a[i] == '1' ? +1 : -1);
            pb[i] = pb[i - 1] + (b[i] == '1' ? +1 : -1);
        }

        bool pos = true;
        bool diff = false;
        FOR(i, 0, n) {
            int x = i > 0 ? pa[i - 1] : 0;
            int y = i > 0 ? pb[i - 1] : 0;

            if (a[i] == b[i]) {
                if (diff) {
                    if (x != 0 || y != 0) {
                        pos = false;
                        break;
                    }
                    diff = false;
                }
            } else {
                if (!diff) {
                    if (x != 0 || y != 0) {
                        pos = false;
                        break;
                    }
                    diff = true;
                }
            }
        }

        cout << (pos ? "YES" : "NO") << '\n';
    }
    return 0;
}