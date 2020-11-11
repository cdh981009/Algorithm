// 10256: Mutation
// https://www.acmicpc.net/problem/10256
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// a node for linked list, value is an index of the needles
struct Node {
    Node* next = nullptr;
    int value;

    /*~Node() {
        if (next)
            delete next;
    }*/
};

constexpr int N = 4;
struct TrieNode {
    char alphabet;
    int terminate = -1;

    TrieNode* children[N];
    TrieNode* failure;

    Node* output;

    TrieNode() {
        FOR(i, 0, N) {
            children[i] = nullptr;
        }
        failure = nullptr;
        output = nullptr;
    }

    ~TrieNode() {
        FOR(i, 0, N) {
            if (children[i])
                delete children[i];
        }
        if (terminate != -1)
            delete output;
    }
};

inline int toNum(const char& c) {
    return c == 'A' ? 0 : c == 'G' ? 1 : c == 'C' ? 2 : 3;
}

// called by root
bool insert(TrieNode* root, const string& s, int id) {
    TrieNode* node = root;
    const char* str = s.c_str();

    while (*str != '\0') {
        if (node->children[toNum(*str)] == nullptr) {
            // insert new child
            TrieNode* newTrieNode = new TrieNode;
            newTrieNode->alphabet = *str;
            node->children[toNum(*str)] = newTrieNode;
        }

        node = node->children[toNum(*str)];
        str++;
    }

    if (node->terminate == -1) {
        node->terminate = id;
        return true;
    } else {
        return false;
    }
}

// aho-corasick failure function computation
void computeFailureFunction(TrieNode* root) {
    queue<TrieNode*> q;
    q.push(root);
    root->failure = root;

    // breadth first search
    while (!q.empty()) {
        // 자식들의 failure function을 계산하고 queue에 넣는다.
        auto node = q.front();
        q.pop();

        FOR(i, 0, N) {
            if (node->children[i] == nullptr)
                continue;

            auto child = node->children[i];
            if (node == root) {
                child->failure = root;
            } else {
                auto t = node->failure;
                while (t != root && t->children[i] == nullptr) {
                    t = t->failure;
                }
                if (t->children[i] != nullptr)
                    t = t->children[i];
                child->failure = t;
            }

            // 실패노드의 아웃풋을 가져온다.
            child->output = child->failure->output;
            if (child->terminate != -1) {
                // child 노드가 종결노드면 (새 needle을 찾았으면) 새 아웃풋을 붙힌다
                Node* newNode = new Node;
                newNode->value = child->terminate;
                newNode->next = child->output;
                child->output = newNode;
            }

            q.push(child);
        }
    }
}

// pair<int, int> = {(s.index), (needle's index that matches, which ends at s.index)}
vector<pair<int, int>> ahoCorasick(const string& s, TrieNode* root) {
    vector<pair<int, int>> ret;
    TrieNode* here = root;

    FOR(i, 0, s.size()) {
        int chr = toNum(s[i]);

        while (here != root && here->children[chr] == nullptr)
            here = here->failure;

        if (here->children[chr] != nullptr)
            here = here->children[chr];

        Node* output = here->output;
        while (output != nullptr) {
            ret.push_back({i, output->value});
            output = output->next;
        }
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<string> needles;
        TrieNode root;

        string dna;
        cin >> dna;
        string marker;
        cin >> marker;

        insert(&root, marker, needles.size());
        needles.push_back(marker);

        FOR(i, 0, m) {
            FOR(j, i + 1, m) {
                string str;

                // reverse marker from i to j
                FOR(k, 0, i) {
                    str.push_back(marker[k]);
                }
                FOR_(k, i, j) {
                    str.push_back(marker[j - (k - i)]);
                }
                FOR(k, j + 1, m) {
                    str.push_back(marker[k]);
                }

                //cout << str << endl;
                if (insert(&root, str, needles.size())) {
                    needles.push_back(str);
                }
            }
        }

        computeFailureFunction(&root);
        cout << (ahoCorasick(dna, &root).size()) << '\n';
    }

    return 0;
}