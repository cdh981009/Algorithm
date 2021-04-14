// 13159: 배열
// https://www.acmicpc.net/problem/13159
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 3e5;

struct Node {
    Node *l, *r, *p;
    int item, subtree, mn, mx;
    long long sum;
    bool reverse;

    Node() {
        l = r = p = nullptr;
        item = subtree = mn = mx = 0;
        sum = 0;
        reverse = false;
    }
} *tree, *nodes[N];

void propagate(Node* x) {
    if (!x->reverse)
        return;
    swap(x->l, x->r);
    x->reverse = false;
    if (x->l)
        x->l->reverse ^= 1;
    if (x->r)
        x->r->reverse ^= 1;
}

void update(Node* x) {
    if (x->l)
        propagate(x->l);
    if (x->r)
        propagate(x->r);
    
    x->subtree = 1 + (x->l ? x->l->subtree : 0) + (x->r ? x->r->subtree : 0);
    x->sum = x->item + (x->l ? x->l->sum : 0) + (x->r ? x->r->sum : 0);
    x->mn = x->mx = x->item;

    if (x->l) {
        x->mn = min(x->mn, x->l->mn);
        x->mx = max(x->mx, x->l->mx);
    }
    if (x->r) {
        x->mn = min(x->mn, x->r->mn);
        x->mx = max(x->mx, x->r->mx);
    }
}

void rotate(Node* x) {
    Node* p = x->p;
    Node* b = nullptr;

    propagate(p);
    propagate(x);

    if (p->l == x) {
        p->l = b = x->r;
        x->r = p;
    } else {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if (b)
        b->p = p;
    
    if (x->p) {
        if (x->p->l == p)
            x->p->l = x;
        else
            x->p->r = x;
    } else {
        tree = x;
    }

    update(p);
    update(x);
}

void splay(Node* x) {
    propagate(x);

    while (x->p) {
        Node* p = x->p;
        Node* g = x->p->p;
        if (g) {
            if ((g->l == p) == (p->l == x))
                rotate(p);
            else
                rotate(x);
        }
        rotate(x);
    }
}

Node* kth(int k) {
    Node* curr = tree;
    while (true) {
        propagate(curr);
        int x = curr->l ? curr->l->subtree : 0;
        if (k == x) {
            break;
        } else if (k < x) {
            curr = curr->l;
        } else {
            k -= x + 1;
            curr = curr->r;
        }
    }
    splay(curr);

    return curr;
}

Node* getRange(int l, int r) {
    Node* ret = nullptr;
    int n = tree->subtree;

    if (l > 0) {
        kth(l - 1);
        if (r < n - 1) {
            Node* oldT = tree;
            tree->r->p = nullptr;
            tree = tree->r;

            kth(r - l + 1);
            ret = tree->l;

            tree->p = oldT;
            oldT->r = tree;
            tree = oldT;
        } else {
            ret = tree->r;
        }
    } else {
        if (r < n - 1) {
            kth(r + 1);
            ret = tree->l;
        } else {
            ret = tree;
        }
    }

    return ret;
}

void reverse(int l, int r) {
    Node* range = getRange(l, r);
    range->reverse ^= 1;
}

void inorder(Node* x) {
    propagate(x);
    update(x);

    if (x->l)
        inorder(x->l);
    cout << x->item << ' ';
    if (x->r)
        inorder(x->r);
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    Node* prev = nullptr;

    FOR(i, 0, n) {
        Node* curr = new Node;
        nodes[i] = curr;
        curr->item = i + 1;
        curr->l = prev;
        if (prev)
            prev->p = curr;
        update(curr);
        prev = curr;
    }
    tree = prev;

    int q;
    cin >> q;
    // queries
    FOR(i, 0, q) {
        int t, l, r, x;
        Node* node;
        cin >> t;
        switch (t) {
        case 1:
        case 2:
            cin >> l >> r;
            l--; r--;
            node = getRange(l, r);
            cout << node->mn << ' '
                 << node->mx << ' '
                 << node->sum << '\n';
            if (t == 1) {
                node->reverse ^= 1;
            } else {
                cin >> x;
                x %= (r - l + 1);
                if (x < 0)
                    x += (r - l + 1);
                if (x != 0) {
                    reverse(l, r);
                    reverse(l, l + x - 1);
                    reverse(l + x, r);
                }
            }
            break;
        case 3:
            cin >> x; x--;
            cout << kth(x)->item << '\n';
            break;
        case 4:
            cin >> x; x--;
            splay(nodes[x]);
            cout << (tree->l ? tree->l->subtree : 0) + 1 << '\n';
            break;
        }
    }

    inorder(tree);
    cout << '\n';

    return 0;
}