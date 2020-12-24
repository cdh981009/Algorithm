// 13159: 배열
// https://www.acmicpc.net/problem/13159
#include <bits/stdc++.h>

using namespace std;

#define INF INT32_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// Splay tree
// 간략한 설명: https://cubelover.tistory.com/10
// 한줄요약: Amortized O(q log n)

// need 2 dummies
constexpr int N = 3e5 + 2;

struct Node {
    Node *l, *r, *p;
    int key;
    int cnt, minK, maxK;
    long long sum;
    bool inv;
    bool trail;

    Node() {
        l = r = p = nullptr;
        inv = trail = false;
    }

    ~Node() {
        if (l)
            delete l;
        if (r)
            delete r;
    }
} * tree, *nodes[N];

void update(Node* x) {
    x->cnt = 1;
    x->minK = x->maxK = x->sum = x->key;
    if (x->l) {
        x->cnt += x->l->cnt;
        x->sum += x->l->sum;
        x->minK = min(x->minK, x->l->minK);
        x->maxK = max(x->maxK, x->l->maxK);
    }
    if (x->r) {
        x->cnt += x->r->cnt;
        x->sum += x->r->sum;
        x->minK = min(x->minK, x->r->minK);
        x->maxK = max(x->maxK, x->r->maxK);
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

// make k-th element the root
// k is 0-base
void findKth(int k) {
    Node* x = tree;
    lazy(x);
    while (1) {
        while (x->l && x->l->cnt > k) {
            x = x->l;
            lazy(x);
        }
        if (x->l)
            k -= x->l->cnt;
        if (!k--)
            break;
        x = x->r;
        lazy(x);
    }
    splay(x);
}

// make tree->r->l subtree of [l...r]
void interval(int l, int r) {
    findKth(l - 1); // is root now
    Node* x = tree;
    tree = x->r;
    tree->p = nullptr;
    findKth(r - l + 1); // is root now
    x->r = tree;
    tree->p = x;
    tree = x;
}

void reverse(int l, int r) {
    interval(l, r);
    Node* x = tree->r->l;
    x->inv = !x->inv;
}

void init(Node* x) {
    if (x->l)
        init(x->l);
    if (x->r)
        init(x->r);
    update(x);
}

// make a[i] = x the root,
// now root->l->cnt is i of a[i] = x;
void findKey(int k) {
    Node* x = nodes[k];
    Node* curr = x;
    while (curr) {
        curr->trail = true;
        curr = curr->p;
    }
    curr = tree;
    while (1) {
        lazy(curr);
        curr->trail = false;
        if (curr == x)
            break;
        if (curr->l && curr->l->trail) {
            curr = curr->l;
        } else if (curr->r && curr->r->trail) {
            curr = curr->r;
        }
    }
    splay(curr);
}

void inorder(Node* x) {
    lazy(x);

    if (x->l)
        inorder(x->l);

    cout << x->key << ' ';

    if (x->r)
        inorder(x->r);
}

void shift(Node* x, int k) {
    assert(k > 0);

    // change the root to node x temporarily
    Node* oldTree = tree;
    Node* oldParent = x->p;
    Node** b = (oldParent->l == x ? &(oldParent->l) : &(oldParent->r));

    tree = x;
    tree->p = nullptr;

    int s = tree->cnt; // = r - l + 1
    findKth(s - 1 - k);

    // now tree's right subtree's cnt is k
    Node* r = tree->r;
    assert(r->cnt == k);
    tree->r = nullptr;
    update(tree);

    findKth(0);
    tree->l = r;
    r->p = tree;
    update(tree);

    tree->p = oldParent;
    *b = tree;
    tree = oldTree;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    tree = new Node;
    tree->key = 0;
    Node* prev = tree;

    FOR_(i, 1, n + 1) {
        Node* curr = new Node;
        curr->key = i;
        curr->p = prev;
        prev->r = curr;
        prev = curr;
        nodes[i] = curr;
    }

    init(tree);

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
            interval(l, r);
            node = tree->r->l;
            cout << node->minK << ' '
                 << node->maxK << ' '
                 << node->sum << '\n';
            if (t == 1) {
                // REVERSE
                node->inv = !node->inv;
            } else {
                cin >> x;
                x %= (r - l + 1);
                if (x < 0)
                    x += (r - l + 1);
                if (x != 0)
                    shift(tree->r->l, x);
            }
            break;
        case 3:
            cin >> x;
            findKth(x);
            cout << tree->key << '\n';
            break;
        case 4:
            cin >> x;
            findKey(x);
            cout << tree->l->cnt << '\n';
            break;
        }
    }

    interval(1, n);
    inorder(tree->r->l);
    cout << '\n';

    return 0;
}