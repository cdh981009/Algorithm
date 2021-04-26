#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 2e5 + 10;

using ll = long long;
int arr[N];
int perm[N];
int root[N];
bool cnt[N];

int n, p;

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    root[y] = x;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> p;

        FOR(i, 0, n) {
            cin >> arr[i];
            perm[i] = i;
            root[i] = i;
            cnt[i] = false;
        }

        sort(perm, perm + n, [](int l, int r) -> bool {
            return arr[l] < arr[r];
        });

        long long ans = 0;
        FOR(i, 0, n) {
            int curr = perm[i];
            int w = arr[curr];

            if (w >= p)
                break;

            int l = curr;
            while (l - 1 >= 0 && arr[l - 1] % w == 0) {
                l--;
                if (!same(curr, l)) {
                    unite(curr, l);
                    ans += w; 
                } else {
                    break;
                }
            }

            int r = curr;
            while (r + 1 < n && arr[r + 1] % w == 0) {
                r++;
                if (!same(curr, r)) {
                    unite(curr, r);
                    ans += w;
                } else {
                    break;
                }
            }
        }

        ll c = 0;
        FOR(i, 0, n) {
            int x = find(i);
            if (!cnt[x]) {
                cnt[x] = true;
                c++;
            }
        }


        ans += (c - 1) * p;

        cout << ans << '\n';
    }
    return 0;
}