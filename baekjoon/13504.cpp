#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5;
constexpr int L = 30;

struct Node {
    Node *c[2] = {nullptr, nullptr};
    
    ~Node() {
        if (c[0])
            delete c[0];
        if (c[1])
            delete c[1];
    }
} *root;
int n;
int ans;

void init() {
    root = new Node;
    auto curr = root;
    for (int i = (1 << L); i > 0; i /= 2) {
        curr->c[0] = new Node;
        curr = curr->c[0];
    }
}

void update(int x) {
    auto curr = root;
    for (int i = (1 << L); i > 0; i /= 2) {
        int d = (x & i) > 0;
        if (curr->c[d] == nullptr)
            curr->c[d] = new Node;
        curr = curr->c[d];
    }
}

int query(int x) {
    auto curr = root;
    int ret = 0;
    for (int i = (1 << L); i > 0; i /= 2) {
        int d = (x & i) == 0;
        if (curr->c[d])
            ret += i, curr = curr->c[d];
        else
            curr = curr->c[!d];
    }

    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        vector<int> v(n);
        FOR(i, 0, n) {
            cin >> v[i];
            if (i > 0)
                v[i] ^= v[i - 1];
        }

        init();
        ans = 0;
        FOR(i, 0, n) {
            update(v[i]);
            int res = query(v[i]);
            ans = max(ans, res);
        }

        cout << ans << '\n';
        delete root;
    }

    return 0;
}