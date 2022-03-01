#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;
using pii = pair<int, int>;

// count(sum) seg tree
struct Seg {
    int n;
    vector<int> sg;
    vector<int> lazy;
    vector<int> &arr;

    Seg(vector<int>& _arr): arr(_arr), n(_arr.size()) {
        sg = vector<int>(4 * n);
        lazy = vector<int>(4 * n, -1);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            sg[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            sg[node] = sg[2 * node] + sg[2 * node + 1];
        }
    }

    void prop(int node, int l, int r) {
        if (lazy[node] == -1) return;
        
        sg[node] = lazy[node] * (r - l + 1);
        
        if (l != r)
            lazy[2 * node] = lazy[2 * node + 1] = lazy[node];

        lazy[node] = -1;
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    int query(int node, int nl, int nr, int ql, int qr) {
        prop(node, nl, nr);

        if (nr < ql || qr < nl) return 0;
        
        if (ql <= nl && nr <= qr) {
            return sg[node];
        }

        int mid = (nl + nr) / 2;
        return query(2 * node, nl, mid, ql, qr) + query(2 * node + 1, mid + 1, nr, ql, qr);
    }

    // set update
    void upd(int l, int r, int x) {
        upd(1, 0, n - 1, l, r, x);
    }

    void upd(int node, int nl, int nr, int ql, int qr, int x) {
        prop(node, nl, nr);

        if (nr < ql || qr < nl) return;

        if (ql <= nl && nr <= qr) {
            sg[node] = (nr - nl + 1) * x;
            if (nl != nr) {
                lazy[2 * node] = x;
                lazy[2 * node + 1] = x;
            }
            return;
        }
        
        int mid = (nl + nr) / 2;
        upd(2 * node, nl, mid, ql, qr, x);
        upd(2 * node + 1, mid + 1, nr, ql, qr, x);
        sg[node] = sg[2 * node] + sg[2 * node + 1];
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q, x;
    cin >> n >> q >> x;

    vector<int> arr(n);
    int pos;

    FOR(i, 0, n) {
        int a; cin >> a;
        if (a < x)
            arr[i] = 1;
        if (a == x) pos = i;
    }

    Seg seg(arr);

    FOR(i, 0, q) {
        int c, l, r;
        cin >> c >> l >> r;
        l--, r--;

        int cnt1 = seg.query(l, r);
        int cnt0 = (r - l + 1) - cnt1;

        if (c == 1) { // ascending
            seg.upd(l, l + cnt1 - 1, 1);
            seg.upd(l + cnt1, r, 0);
        } else { // descending
            seg.upd(l, l + cnt0 - 1, 0);
            seg.upd(l + cnt0, r, 1);
        }

        if (l <= pos && pos <= r) {
            if (c == 1) {
                pos = l + cnt1;
            } else {
                pos = l + cnt0 - 1;
            }
        }
    }

    cout << pos + 1 << '\n';
    return 0;
}