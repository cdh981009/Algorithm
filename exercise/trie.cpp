#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct trieNode {
    trieNode* child[26];
    bool eow = false;

    trieNode() {
        FOR(i, 0, 26)
        child[i] = nullptr;
    }

    bool find(string s) {
        size_t i = 0;

        auto* node = this;
        while (i < s.length()) {
            int ch = s[i] - 'a';
            if (!node->child[ch])
                return false;
            node = node->child[ch];
            ++i;
        }
        return node->eow;
    }

    void insert(string s) {
        size_t i = 0;

        auto* node = this;
        while (i < s.length()) {
            int ch = s[i] - 'a';
            if (!node->child[ch])
                node->child[ch] = new trieNode();
            node = node->child[ch];
            ++i;
            if (i == s.length())
                node->eow = true;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    trieNode root;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        root.insert(s);
    }
    int cnt = 0;
    FOR(i, 0, m) {
        string s;
        cin >> s;
        /*
        if (root.find(s)) {
            cout << s << endl;
        }
        */
        cnt += root.find(s);
    }
    cout << cnt << "\n";

    return 0;
}