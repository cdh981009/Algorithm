#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct Node {
	string value;
	map<string, Node> children;

	bool hasChild(string v) {
		return children.count(v);
	}

	void insertChild(string v) {
		children[v] = {v};
	}

	Node& getChild(string v) {
		return children.at(v);
	}
};

void print(const Node& node, int depth) {
	for (auto p : node.children) {
		FOR(i, 0, depth)
			cout << "--";
		cout << p.first << "\n";
		print(p.second, depth+1);
	}
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	Node root;
	int n; cin >> n;
	FOR(i, 0, n) {
		int m; cin >> m;
		Node* node = &root;
		FOR(i, 0, m) {
			string v; cin >> v;
			if (!node->hasChild(v))
				node->insertChild(v);
			node = &(node->getChild(v));
		}
	}

	print(root, 0);
    return 0;
}