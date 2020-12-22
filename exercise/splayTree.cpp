// 3444: robotic sort
// https://www.acmicpc.net/problem/3444
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Splay tree

struct Node {
    Node *l, *r, *p;
    pair<int, int> key, minKey;
    int cnt;
    bool inv;

    Node() {
        l = r = p = nullptr;
        inv = false;
    }

    ~Node() {
        if (l)
            delete l;
        if (r)
            delete r;
    }
} * tree;

void update(Node* x) {
    x->cnt = 1;
    x->minKey = x->key;
    if (x->l) {
        x->cnt += x->l->cnt;
        x->minKey = min(x->minKey, x->l->minKey);
    }
    if (x->r) {
        x->cnt += x->r->cnt;
        x->minKey = min(x->minKey, x->r->minKey);
    }
}

void rotate(Node* x) {
    Node* p = x->p;
    Node* b;
    if (x == p->l) {
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
    (x->p ? (p == x->p->l ? x->p->l : x->p->r) : tree) = x;

    update(p);
    update(x);
}

void splay(Node* x) {
    while (x->p) {
        Node* p = x->p;
        Node* g = p->p;
        if (g)
            rotate((x == p->l) == (p == g->l) ? p : x);
        rotate(x);
    }
}

// lazy flip
void lazy(Node* x) {
    if (!x->inv)
        return;
    Node* t = x->l;
    x->l = x->r;
    x->r = t;
    x->inv = false;
    if (x->l)
        x->l->inv = !x->l->inv;
    if (x->r)
        x->r->inv = !x->r->inv;
}

// void findKth(int k) {
//     Node *x = tree;
//     lazy(x);
//     while (1) {
//         while (x->l && x->l->cnt > k) {
//             x = x->l;
//             lazy(x);
//         }
//         if (x->l) k -= x->l->cnt;
//         if (!k--) break;
//         x = x->r;
//         lazy(x);
//     }
//     splay(x);
// }

// // make tree->r->l subtree of [l...r]
// void interval(int l, int r) {
//     findKth(l - 1); // is root now
//     Node *x = tree;
//     tree = x->r;
//     tree->p = nullptr;
//     findKth(r - l + 1); // is root now
//     x->r = tree;
//     tree->p = x;
//     tree = x;
// }

// void reverse(int l, int r) {
//     interval(l, r);
//     Node* x = tree->r->l;
//     x->inv = !x->inv;
// }

void init(Node* x) {
    if (x->l)
        init(x->l);
    if (x->r)
        init(x->r);
    update(x);
}

void deleteRoot() {
    if (!tree)
        return;

    Node* old = tree;
    lazy(old);

    if (old->l) {
        if (old->r) {
            // has both children
            tree = old->l;
            tree->p = nullptr;

            Node* x = tree;
            lazy(x);
            while (x->r) {
                x = x->r;
                lazy(x);
            }

            x->r = old->r;
            update(x); // in case x is already root

            old->r->p = x;
            splay(x);

            old->l = old->r = nullptr;
            delete old;

            return;
        }

        // only left child
        tree = old->l;
        tree->p = nullptr;
        old->l = nullptr;
        delete old;

        return;
    }
    if (old->r) {
        // only right child
        tree = old->r;
        tree->p = nullptr;
        old->r = nullptr;
        delete old;

        return;
    }

    // no child
    delete tree;
    tree = nullptr;

    return;
}

void findIndexOfMin(Node* x) {
    while (true) {
        lazy(x);
        if (x->minKey == x->key) {
            splay(x);
            return;
        } else {
            auto leftMin = (x->l ? x->l->minKey : pair<int, int>(INF, INF));
            auto rightMin = (x->r ? x->r->minKey : pair<int, int>(INF, INF));

            if (leftMin < rightMin) {
                x = x->l;
            } else {
                x = x->r;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        // init as degenerate tree;
        // tree represents an array
        tree = nullptr;
        Node* prev = nullptr;

        FOR(i, 0, n) {
            Node* curr = new Node;
            cin >> curr->key.first;
            curr->key.second = i + 1;

            if (!tree)
                tree = curr;
            if (prev)
                prev->r = curr;
            curr->p = prev;

            prev = curr;
        }

        init(tree);

        // queries
        FOR_(i, 1, n) {
            // 1. find minimum value and splay it to the root
            findIndexOfMin(tree);
            // 한번 할 때마다 수열의 맨 앞을 잘라내기 때문에 i를 더해줘야 함
            int ind = i + ((tree->l) ? tree->l->cnt : 0);
            cout << ind << ' ';

            // 2. inverse left children (lazy propagation)
            if (tree->l) {
                tree->l->inv = !tree->l->inv;
            }

            // 3. delete root
            deleteRoot();
        }
        cout << '\n';

        // clear
        delete tree;
    }

    return 0;
}