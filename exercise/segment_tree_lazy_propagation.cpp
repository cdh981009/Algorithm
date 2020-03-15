#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
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
            return INT32_MIN;
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
        cout << "size is: " << n << endl;
        for (int i = 0; i < n; ++i)
            segTree[n + i] = (i < v.size() ? v[i] : INT32_MIN); 
        for (int i = n - 1; i > 0; --i) 
            segTree[i] = max(segTree[2*i], segTree[2*i + 1]);
    }

    SegTree(const vector<int>& v) {
        init(v);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    cout << "len is " << len << endl;
    vector<int> arr(len);
    int i = 0;
    while (len--) {
        int x; cin >> x;
        arr[i++] = x;
    }

    SegTree tree(arr);
    cout << "init complete" << endl;
    cout << tree.query(0, 0) << endl;
    cout << tree.query(0, 3) << endl;
    tree.range_update(0, 1, 5);
    tree.range_update(1, 1, 2);
    cout << tree.query(0, 0) << endl;
    cout << tree.query(1, 1) << endl;
    cout << tree.query(0, 3) << endl;
    cout << tree.query(2, 3) << endl;
    return 0;
}