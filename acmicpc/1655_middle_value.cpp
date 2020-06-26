#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int nums; cin >> nums;
	priority_queue<int, vector<int>, less<int>> maxH;
	priority_queue<int, vector<int>, greater<int>> minH;
	while (nums--) {
		int x; cin >> x;
		if (maxH.empty() || x <= maxH.top()) {
			maxH.push(x);
			if (maxH.size() > minH.size() + 1) {
				minH.push(maxH.top());
				maxH.pop();
			}
		} else {
			minH.push(x);
			if (maxH.size() < minH.size()) {
				maxH.push(minH.top());
				minH.pop();
			}
		}
		int m, k;
		m = maxH.empty() ? INF : maxH.top();
		k = minH.empty() ? INF : minH.top();
		cout << min(m, k) << "\n";
	}
    return 0;
}