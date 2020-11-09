// 11479: 서로 다른 부분 문자열의 개수 2
// https://www.acmicpc.net/problem/11479
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// a node for linked list, value is an index of the needles
struct Node {
    Node* next = nullptr;
    int value;
};

struct TrieNode {
    char alphabet;
    int terminate = -1;

    TrieNode* children[26];
    TrieNode* failure;

    Node* output;

    TrieNode() {
        FOR(i, 0, 26) {
            children[i] = nullptr;
        }
        failure = nullptr;
        output = nullptr;
    }
};

// called by root
void insert(TrieNode* root, const string& s, int id) {
    TrieNode* node = root;
    const char* str = s.c_str();

    while (*str != '\0') {
        if (node->children[*str - 'a'] == nullptr) {
            // insert new child
            TrieNode* newTrieNode = new TrieNode;
            newTrieNode->alphabet = *str;
            node->children[*str - 'a'] = newTrieNode;
        }

        node = node->children[*str - 'a'];
        str++;
    }

    node->terminate = id;
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

        FOR(i, 0, 26) {
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
        int chr = s[i] - 'a';

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

    int n;
    cin >> n;

    vector<string> needles;
    TrieNode root;

    FOR(i, 0, n) {
        string str;
        cin >> str;

        insert(&root, str, needles.size());
        needles.push_back(str);
    }

    computeFailureFunction(&root);

    int m;
    cin >> m;
    FOR(i, 0, m) {
        string hayStack;
        cin >> hayStack;

        cout << (ahoCorasick(hayStack, &root).empty() ? "NO" : "YES") << '\n';
    }

    return 0;
}