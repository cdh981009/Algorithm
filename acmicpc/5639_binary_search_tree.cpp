#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct node {
    int val;
    node* left = nullptr;
    node* right = nullptr;
};

void postorder(node* n) {
    if (n == nullptr)
        return;
    auto l = n->left;
    auto r = n->right;
    postorder(l);
    postorder(r);
    cout << n->val << "\n";
}

void insert(node* root, node* n) {
    if (root->val < n->val) {
        if (root->right == nullptr)
            root->right = n;
        else
            insert(root->right, n);
    } else {
        if (root->left == nullptr)
            root->left = n;
        else
            insert(root->left, n);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    node* root = nullptr;
    while (cin >> num) {
        node* n = new node {num};
        if (!root)
            root = n;
        else
            insert(root, n);
    }

    postorder(root);
    return 0;
}