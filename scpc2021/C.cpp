#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;

int n;
string str;

struct comp {
    int t;
    const vector<int> &x;
    comp(int t, const vector<int>& x): t(t), x(x) {}
    bool operator()(int a, int b) {
        return x[a] == x[b] ? x[a + t] < x[b + t] : x[a] < x[b];
    }
};

vector<int> getSA() {
    vector<int> perm(n);
    vector<int> g(n + 1);
    vector<int> q(n + 1);
    g[n] = q[n] = -1;
    int t = 1;

    FOR(i, 0, n) {
        perm[i] = i;
        g[i] = str[i];
    }

    while (true) {
        comp _2t(t, g);
        sort(perm.begin(), perm.end(), _2t);

        if (2 * t > n)
            break;
        t *= 2;

        q[perm[0]] = 0;
        FOR(i, 1, n) {
            if (_2t(perm[i - 1], perm[i]))
                q[perm[i]] = q[perm[i - 1]] + 1;
            else
                q[perm[i]] = q[perm[i - 1]];
        }

        swap(g, q);
    }

    return perm;
}

int main(int argc, char** argv) {
    int T, tc;

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n >> str;

        auto sa = getSA();
        vector<int> str2SA(n);

        FOR(i, 0, n) {
            str2SA[sa[i]] = i;
        }

        cout << "Case #" << tc + 1 << endl;
        vector<int> ans;

        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && str2SA[j] >= str2SA[i]) {
                j++;
            }

            ans.push_back(j - i);
            i = j;
        }

        cout << ans.size() << '\n';
        FOR(i, 0, ans.size()) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        
    }

    return 0;
}