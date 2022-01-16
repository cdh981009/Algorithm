#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

constexpr int N = 3e5;
constexpr int L = 30;

pii arr[N];
int prv[N];
int ans, ansi;

int n, k;

struct Trie {
    Trie* child[2] = {nullptr, nullptr};
    int v = 0, i = -1;
} *root;

pii query(int ind) {
    int m, mi;
    m = 0;
    mi = -1;

    auto op = [&](int v, int i) {
        if (v > m) {
            m = v;
            mi = i;
        }
    };

    Trie* curr = root;
    for (int i = (1 << L); i > 0; i /= 2) {
        bool x = (arr[ind].first & i);
        if (k & i) {  // if k's bit is 1, move to !x
            if (curr->child[!x] == nullptr) curr->child[!x] = new Trie;
            curr = curr->child[!x];
        } else {  // if k's bit is 0, move to x. Then get dp from !x
            if (curr->child[x] == nullptr) curr->child[x] = new Trie;
            if (curr->child[!x]) {
                op(curr->child[!x]->v, curr->child[!x]->i);
            }
            curr = curr->child[x];
        }
    }

    // xor is same as k
    op(curr->v, curr->i);

    return {m, mi};
}

void insert(int ind, int v) {
    Trie* curr = root;
    for (int i = (1 << L); i > 0; i /= 2) {
        bool x = (arr[ind].first & i);
        if (curr->child[x] == nullptr)
            curr->child[x] = new Trie;
        curr = curr->child[x];
        if (curr->v < v) {
            curr->v = v;
            curr->i = ind;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    FOR(i, 0, n) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + n);

    root = new Trie;
    ans = 0;

    if (k == 0) {
        cout << n << '\n';
        FOR(i, 0, n) {
            if (i != 0)
                cout << ' ';
            cout << i + 1;
        }
        cout << '\n';
    } else {
        FOR(i, 0, n) {
            auto res = query(i);
            res.first++;
            prv[i] = res.second;
            if (res.first > ans) {
                ans = res.first;
                ansi = i;
            }
            insert(i, res.first);
        }

        if (ans <= 1) {
            cout << -1 << '\n';
        } else {
            /* output */
            int curr = ansi;
            vector<int> aux;
            while (curr != -1) {
                aux.push_back(arr[curr].second + 1);
                curr = prv[curr];
            }
            cout << aux.size() << '\n';
            for (auto x : aux) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}