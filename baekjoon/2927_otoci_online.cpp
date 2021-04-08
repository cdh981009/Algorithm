// 2927: OTOCI
// https://www.acmicpc.net/problem/2927
#include <bits/stdc++.h>

using namespace std;

#define INF 1987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 3e4 + 5;

// 본 문제는 백준의 한계에 의해 오프라인 쿼리로 풀 수 있게 되어 있으나
// 원본 문제는 한 쿼리에 대해 답을 내야 다음 쿼리가 주어진다
// 따라서 HLD로 풀 수 없고 LCT를 사용해야 한다

// link-cut tree
int n, q;

// Splay nodes
struct Node {
    Node *l, *r, *p, *pp;
    int val, sum;
    bool rev;

    Node() {
        l = r = p = pp = nullptr;
        val = sum = 0;
        rev = false;
    }
} *nodes[N];

void update(Node* x) {
    x->sum = x->val + (x->l ? x->l->sum : 0) + (x->r ? x->r->sum : 0);
}

void propagate(Node* x) {
    if (x->rev) {
        swap(x->r, x->l);
        if (x->l)
            x->l->rev = !(x->l->rev);
        if (x->r)
            x->r->rev = !(x->r->rev);
        x->rev = false;
    }
}

void rotate(Node* x) {
    Node* p = x->p;
    propagate(p);
    propagate(x);

    Node* b;
    if (x == p->l) {
        p->l = b = x->r;
        x->r = p;
    } else {
        p->r = b = x->l;
        x->l = p;
    }
    if (b)
        b->p = p;
    x->p = p->p;
    p->p = x;

    if (x->p) {
        if (x->p->l == p) x->p->l = x;
        if (x->p->r == p) x->p->r = x;
    }

    if (p->pp) {
        x->pp = p->pp;
        p->pp = nullptr;
    }

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

void access(Node* x) {
    splay(x);
    propagate(x);

    if (x->r) {
        x->r->pp = x;
        x->r->p = nullptr;
        x->r = nullptr;
    }
    update(x);

    while (x->pp) {
        Node* pp = x->pp;
        splay(pp);
        propagate(pp);
        if (pp->r) {
            pp->r->pp = pp;
            pp->r->p = nullptr;
        }
        x->pp = nullptr;
        x->p = pp;
        pp->r = x;
        update(pp);
        splay(x);
    }
}

Node* findRoot(Node* x) {
    access(x);
    propagate(x);
    while (x->l) {
        x = x->l;
        propagate(x);
    }
    access(x);
    return x;
}

void updateVal(Node* x, int v) {
    access(x);
    x->val = v;
    update(x);
}

Node* lca(Node* x, Node* y) {
    access(x);
    access(y);
    splay(x);
    return (x->pp ? x->pp : x);
}

// 트리의 루트부터 해당 노드까지 합
int rootSum(Node* x) {
    access(x);
    return x->sum;
}

int pathSum(Node* x, Node* y) {
    int ans = 0;
    ans += rootSum(x);
    ans += rootSum(y);
    auto a = lca(x, y);
    ans += -2 * rootSum(a) + a->val;

    return ans;
}

void link(Node* x, Node* y) {
    access(x);
    access(y);
    y->rev = !y->rev;
    // y is now root of a tree
    propagate(y);
    // make y child of x
    y->l = x;
    x->p = y;
    update(y);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR_(i, 1, n) {
        nodes[i] = new Node();
        cin >> nodes[i]->val;
        nodes[i]->sum = nodes[i]->val;
    }

    cin >> q;

    string ts;
    FOR(i, 0, q) {
        int x, y;
        cin >> ts >> x >> y;
        if (ts[0] == 'b') {
            if (findRoot(nodes[x]) != findRoot(nodes[y])) {
                link(nodes[x], nodes[y]);
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else if (ts[0] == 'p') {
            updateVal(nodes[x], y);
        } else {
            if (findRoot(nodes[x]) == findRoot(nodes[y])) {
                cout << pathSum(nodes[x], nodes[y]) << '\n';
            } else {
                cout << "impossible\n";
            }
        }
    }

    return 0;
}