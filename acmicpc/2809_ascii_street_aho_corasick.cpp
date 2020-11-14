// 2809: POPLOČAVANJE
// https://www.acmicpc.net/problem/2809
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct TrieNode {
    int terminate = -1;
    int exist = 0;
    vector<TrieNode*> children;
    TrieNode* failure;
};

bool childExists(TrieNode* node, char c) {
    return (node->exist & (1 << (c - 'a')));
}

// 만약 c에 대응하는 child가 존재한다면 벡터의 몇번 index에 존재하는가
int charToInd(TrieNode* node, char c) {
    int cnt = 0;
    FOR(i, 0, c - 'a') {
        cnt += (node->exist & (1 << (i))) ? 1 : 0;
    }

    return cnt;
}

void addChild(TrieNode* node, char c, TrieNode* child) {
    node->children.insert(node->children.begin() + charToInd(node, c), child);
    node->exist |= (1 << (c - 'a'));
}

// called by root
void insert(TrieNode* root, const string& s) {
    TrieNode* node = root;

    int i = 0;
    while (i < s.size()) {
        auto& c = s[i];
        if (!childExists(node, c)) {
            // insert new child
            addChild(node, c, new TrieNode);
        }

        node = node->children[charToInd(node, c)];
        i++;
    }

    node->terminate = s.size();
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
            if (!(node->exist & (1 << i)))
                continue;

            auto c = 'a' + i;
            auto child = node->children[charToInd(node, c)];

            if (node == root) {
                child->failure = root;
            } else {
                auto t = node->failure;

                while (t != root && childExists(t, c) == false) {
                    t = t->failure;
                }

                if (childExists(t, c))
                    t = t->children[charToInd(t, c)];

                child->failure = t;
            }

            child->terminate = max(child->terminate, child->failure->terminate);

            q.push(child);
        }
    }
}

// 리턴 벡터는 겹치는 tile의 갯수
vector<int> ahoCorasick(const string& s, TrieNode* root) {
    vector<int> ret(s.size() + 1, 0);
    TrieNode* here = root;

    FOR(i, 0, s.size()) {
        auto chr = s[i];

        while (here != root && !childExists(here, chr))
            here = here->failure;

        if (childExists(here, chr))
            here = here->children[charToInd(here, chr)];

        if (here->terminate != -1) {
            ret[i - here->terminate + 1]++;
            ret[i + 1]--;
        }
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    TrieNode* root = new TrieNode;

    int n;
    cin >> n;
    string haystack;
    cin >> haystack;

    int m;
    cin >> m;
    FOR(i, 0, m) {
        string str;
        cin >> str;
        insert(root, str);
    }

    computeFailureFunction(root);

    auto res = ahoCorasick(haystack, root);

    long long cnt = 0;
    int ans = 0;
    FOR(i, 0, n) {
        cnt += res[i];
        ans += (cnt == 0);
    }

    cout << ans << '\n';

    return 0;
}