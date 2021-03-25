#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 26;
int n;
vector<pair<char, char>> children(N);

void preorder(int node) {
    if (node == -1) return;
    auto c = children[node];
    int l = c.first;
    int r = c.second;
    cout << char(node + 'A');
    preorder(l);
    preorder(r);
}

void inorder(int node) {
    if (node == -1)
        return;
    auto c = children[node];
    int l = c.first;
    int r = c.second;
    inorder(l);
    cout << char(node + 'A');
    inorder(r);
}

void postorder(int node) {
    if (node == -1)
        return;
    auto c = children[node];
    int l = c.first;
    int r = c.second;
    postorder(l);
    postorder(r);
    cout << char(node + 'A');
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    FOR(i, 0, n) {
        char p, l, r; cin >> p >> l >> r;
        children[p - 'A'] = {l == '.' ? -1 : l - 'A', r == '.' ? -1 : r - 'A'};
    }

    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);

    return 0;
}