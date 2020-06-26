#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int s, n; cin >> s >> n;
    deque<int> deq;
    int ans = 0;
    FOR_(i, 1, s)
        deq.push_back(i);
    FOR(i, 0, n) {
        int p; cin >> p;
        int ind;
        FOR(i, 0, deq.size()) {
            if (deq[i] == p) {
                ind = i;
                break;
            }
        }
        
        ans += min(ind, (int)deq.size() - ind);
        //cout << ans << endl;
        while (deq.front() != p) {
            deq.push_back(deq.front());
            deq.pop_front();
        }
        deq.pop_front();
    }
    cout << ans << endl;
    return 0;
}