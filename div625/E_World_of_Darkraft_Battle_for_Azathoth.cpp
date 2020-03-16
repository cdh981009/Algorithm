#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
int w, a, m;
typedef tuple<int, int, int> tiii;
 
static const int N = 1 << 20;
int n; // 실제 segTree는 [0, 2*n - 1]
int segTree[N];
int lazy[N] = {0, };
 
struct SegTree {
    // max seg tree에서 lazy가 0 이 아니라면 node가 나타내는 범위 전체에 addition이 되었음을 의미한다
    // 즉 대푯값 (범위 max값)에 lazy[node] 만큼 더해줘야 한다.
 
    void update_lazy(int node, int nodeLeft, int nodeRight) {
        if (lazy[node] != 0) {
            int l = lazy[node];
            segTree[node] += l;
            if (nodeLeft != nodeRight) {
                lazy[node*2] += l;
                lazy[node*2+1] += l;
            }
            lazy[node] = 0;
        }
    }
    // node가 표현하는 범위가 nodeLeft, nodeRight일 때
    // 이 범위와 left, right의 교집합에서 query result를 구한다.
    // top-down
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        update_lazy(node, nodeLeft, nodeRight);
        // 아예 겹치지 않을 떄
        if (right < nodeLeft || left > nodeRight)
            return -1e9;
        // 현재 노드가 나타내는 범위 [nodeLeft, nodeRight]가 [left, right]에 완전히 들어갈 때
        if (nodeLeft >= left && nodeRight <= right) {
            return segTree[node];
        }
        // 현재 노드가 나타내는 범위 [nodeLeft, nodeRight]가 더 크거나, 범위가 겹쳐있을 때
        int mid = (nodeLeft + nodeRight)/2;
        return max(query(left, right, node*2, nodeLeft, mid),
                   query(left, right, node*2+1, mid+1, nodeRight));
    }
 
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
 
    // lazy propagation
    // range addition version
    void range_update(int left, int right, int val, int node, int nodeLeft, int nodeRight) {
        update_lazy(node, nodeLeft, nodeRight);
        // 아예 겹치지 않을 떄
        if (right < nodeLeft || left > nodeRight)
            return;
        // [left, right]가 [nodeLeft, nodeRight]에 완전히 들어갈 때
        if (nodeLeft >= left && nodeRight <= right) {
            // max 값도 +val 될 것이다
            segTree[node] += val;
            if (nodeLeft != nodeRight) {
                lazy[node*2] += val;
                lazy[node*2+1] += val;
            }
            return;
        }
        // [nodeLeft, nodeRight]가 더 크거나, 범위가 겹쳐있을 때
        int mid = (nodeLeft + nodeRight)/2;
        range_update(left, right, val, node*2, nodeLeft, mid);
        range_update(left, right, val, node*2+1, mid+1, nodeRight);
        // 자식중 일부만 값이 바뀌었을 수 있음
        segTree[node] = max(segTree[node*2], segTree[node*2+1]);
    }
 
    void range_update(int left, int right, int val) {
        range_update(left, right, val, 1, 0, n-1);
    }
 
    static inline int power2RoundUp(int x) {
        int i;
        for (i = 1; i < x; i = i << 1);
        return i;
    }
 
    void init(const vector<int>& v) {
        n = power2RoundUp(v.size());
        // cout << "size is: " << n << endl;
        for (int i = 0; i < n; ++i)
            segTree[n + i] = (i < v.size() ? v[i] : -1e9); 
        for (int i = n - 1; i > 0; --i) 
            segTree[i] = max(segTree[2*i], segTree[2*i + 1]);
    }
 
    SegTree(const vector<int>& v) {
        init(v);
    }
 
    void print() {
        FOR(i, 0, n)
            cout << query(i, i) << " ";
        cout << "\n";
    }
};
 
vector<tiii> monsters;
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> w >> a >> m;
    vector<pair<int, int>> weapon(w);
    vector<pair<int, int>> armor(a);
 
    int minWpnCost = INT32_MAX;
    FOR(i, 0, w) {
        int atk, c; cin >> atk >> c;
        weapon[i] = {atk, c};
        minWpnCost = min(minWpnCost, c);
    }
    
    sort(weapon.begin(), weapon.end());
 
    vector<pair<int, int>> refWpn;
    FOR(i, 0, w) {
        auto p = weapon[i];
        while(!refWpn.empty() && refWpn.back().second >= p.second)
            refWpn.pop_back();
        if (refWpn.empty() || refWpn.back().first != p.first)
            refWpn.push_back(p);
    }
    //cout << "ref : " << refWpn.size() << endl;
  
    int minAmrCost = INT32_MAX;
    FOR(i, 0, a) {
        int def, c; cin >> def >> c;
        armor[i] = {def, c};
        minAmrCost = min(minAmrCost, c);
    }
    sort(armor.begin(), armor.end());
 
    FOR_(i, 1, m) {
        int def, atk, g; cin >> def >> atk >> g;
        monsters.push_back({def, atk, g});
    }
    sort(monsters.begin(), monsters.end(),
        [](const tiii& lhs, const tiii& rhs) -> bool { return get<0>(lhs) < get<0>(rhs); });
 
    vector<int> attackIndex(monsters.size());
    FOR(i, 0, monsters.size())
        attackIndex[i] = get<0>(monsters[i]);
 
    //cout << monsters.size() << endl;
    vector<int> preSum(monsters.size(), 0);
    SegTree tree(preSum);
 
    int prevInd = 0;
    FOR(i, 0, refWpn.size()) {
        int updateInd = lower_bound(attackIndex.begin(), attackIndex.end(), refWpn[i].first) - attackIndex.begin();
        tree.range_update(prevInd, updateInd - 1, -refWpn[i].second);
        prevInd = updateInd;
    }
    tree.range_update(prevInd, preSum.size() - 1, -1e9);
 
    sort(monsters.begin(), monsters.end(),
        [](const tiii& lhs, const tiii& rhs) -> bool { return get<1>(lhs) < get<1>(rhs); });
    
    int armorIndex = 0;
    int maxProfit = - minWpnCost - minAmrCost;
    FOR(i, 0, monsters.size()) {
        auto mnstr = monsters[i];
        int updateInd = lower_bound(attackIndex.begin(), attackIndex.end(), get<0>(mnstr)) - attackIndex.begin();
        while (armorIndex < armor.size() && get<1>(mnstr) >= armor[armorIndex].first) {
            maxProfit = max(maxProfit, tree.query(0, preSum.size() - 1) - armor[armorIndex].second);
            armorIndex++;
        }
        tree.range_update(updateInd, preSum.size() - 1, get<2>(mnstr));
        //tree.print();
    }
 
    while (armorIndex < armor.size()) {
        maxProfit = max(maxProfit, tree.query(0, preSum.size() - 1) - armor[armorIndex].second);
        armorIndex++;
    }
 
    cout << maxProfit << endl;
    return 0;
}