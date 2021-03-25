#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    deque<int> q; 
    FOR(i, 0, n) {
        q.push_front(i + 1);
    }
    while (q.size() > 1) {
        q.pop_back();
        q.push_front(q.back());
        q.pop_back();
    }

    cout << q.back() << endl;
    return 0;
}