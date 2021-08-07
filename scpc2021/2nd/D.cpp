#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 101010;
constexpr int A = 26;

int n, k;
ll ans;
string hay, p;

bool match(string& s1, int i1, string& s2, int i2, int l) {
    bool ret = true;
    int ind[A];
    bool occ[A];

    memset(ind, -1, sizeof(int) * A);
    memset(occ, 0, sizeof(bool) * A);

    FOR(i, 0, l) {
        if (ind[s1[i1] - 'a'] == -1) {
            if (occ[s2[i2] - 'a']) {
                ret = false;
                break;
            }
            ind[s1[i1] - 'a'] = s2[i2];
            occ[s2[i2] - 'a'] = true;
        } else if (s2[i2] != ind[s1[i1] - 'a']) {
            ret = false;
            break;
        }
        i1++;
        i2++;
    }

    return ret;
}

struct Node {
    bool terminal = false;
    ll score = 0;

    int cnt = 0;
    int perm[A];
    string str;

    Node* fail = nullptr;
    Node* children[A];

    Node() {
        memset(perm, -1, sizeof(int) * A);
        FOR(i, 0, A) {
            children[i] = nullptr;
        }
    }

    ~Node() {
        FOR(i, 0, A) {
            if (children[i])
                delete children[i];
        }
    }
} * root;

void insert(string& p, int score) {
    Node* node = root;

    int ind[A];
    bool occ[A];
    int cnt = 0;

    memset(ind, -1, sizeof(int) * A);
    memset(occ, 0, sizeof(bool) * A);

    FOR(i, 0, p.size()) {
        char c = p[i] - 'a';
        if (ind[c] == -1) {
            ind[c] = cnt++;
        }
        c = ind[c];

        if (node->children[c] == nullptr) {
            Node* nn = new Node;
            nn->str = node->str;
            nn->str += 'a' + c;
            nn->cnt = cnt;
            node->children[c] = nn;
        }

        node = node->children[c];
    }

    node->terminal = true;
    node->score += score;
}

void fail() {
    queue<Node*> q;
    q.push(root);
    root->fail = root;

    // bfs
    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        FOR(i, 0, A) {
            if (node->children[i] == nullptr)
                continue;

            auto child = node->children[i];
            if (node == root) {
                child->fail = root;
            } else {
                auto t = node->fail;

                auto setPerm = [&]() {
                    int s = t->str.size();
                    int cs = child->str.size();

                    memset(child->perm, -1, sizeof(int) * A);
                    FOR(j, 0, s) {
                        int c1 = t->str[j] - 'a';
                        int c2 = child->str[cs - 1 - s + j] - 'a';
                        child->perm[c2] = c1;
                    }
                    if (child->perm[i] == -1) {
                        child->perm[i] = t->cnt;
                    }
                };
                setPerm();

                while (t != root && t->children[child->perm[i]] == nullptr) {
                    t = t->fail;
                    setPerm();
                }

                if (t->children[child->perm[i]] != nullptr) {
                    t = t->children[child->perm[i]];
                    // setPerm();
                }
                child->fail = t;
            }

            child->score += child->fail->score;
            q.push(child);
        }
    }
}

void search() {
    Node* here = root;

    int ind[A];
    int cnt = 0;
    memset(ind, -1, sizeof(int) * A);

    FOR(i, 0, hay.size()) {
        int c = hay[i] - 'a';
        if (ind[c] == -1)
            ind[c] = cnt++;
        int ic = ind[c];

        while (here != root && here->children[ic] == nullptr) {
            FOR(i, 0, A) {
                if (ind[i] != -1)
                    ind[i] = here->perm[ind[i]];
            }
            cnt = here->fail->cnt;
            if (ind[c] == -1)
                ind[c] = cnt++;
            ic = ind[c];
            here = here->fail;
        }

        if (here->children[ic] != nullptr)
            here = here->children[ic];

        //if (here->terminal == true)
            ans += here->score;
    }
}

int main(int argc, char** argv) {
    int T, tc;

    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (tc = 0; tc < T; tc++) {
        cin >> n >> k;
        cin >> hay;
        ans = 0;

        root = new Node();
        FOR(i, 0, k) {
            cin >> p;
            insert(p, i + 1);
        }
        fail();
        search();

        cout << "Case #" << tc + 1 << endl;
        cout << ans << endl;

        delete root;
        root = nullptr;
    }

    return 0;
}