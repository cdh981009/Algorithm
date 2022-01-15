#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 1e5;
int n;
int ans;

struct Node {
    Node *l = 0, *r = 0;
    bool v = false;
};
Node *root = new Node;

void dfs(Node* node) {
    if (node == nullptr)
        return;
    
    if (node->v || (node->l && node->r)) {
        ans++;
        if (node->l) node->l->v = true;
        if (node->r) node->r->v = true;
    }

    dfs(node->l);
    dfs(node->r);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> aux;

    cin >> n;
    FOR(i, 0, n) {
        ll x; cin >> x;
        aux.clear();
        while (x > 0) {
            aux.push_back(x);
            x /= 2;
        }

        Node* curr;
        for (int j = aux.size() - 1; j >= 0; --j) {
            if (j == aux.size() - 1) {
                curr = root;
            } else {
                if (2 * aux[j + 1] == aux[j]) {
                    if (curr->l == nullptr)
                        curr->l = new Node;
                    curr = curr->l;
                } else {
                    if (curr->r == nullptr)
                        curr->r = new Node;
                    curr = curr->r;
                }
            }

            if (j == 0) {
                curr->v = true;
            }
        }
    }

    dfs(root);

    cout << ans << '\n';

    return 0;
}