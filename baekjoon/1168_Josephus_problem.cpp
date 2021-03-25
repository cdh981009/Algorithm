// 1168: 요세푸스 문제 2
// https://www.acmicpc.net/problem/1168
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 18);
int n;
// 1-based array
int segTree[N];

// cnt tree
void initTree(int sz) {
    for (n = 1; n < sz; n <<= 1)
        ;
    for (int i = 0; i < n; ++i) {
        segTree[i + n] = (i < sz ? 1 : 0 /*default vaule*/);
    }
    for (int i = n - 1; i >= 1; --i) {
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }
}

void pointUpdate(int ind, int val) {
    ind += n;
    segTree[ind] = val;
    while (ind > 1) {
        ind >>= 1;
        segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
    }
}

// 0 base
int kthRemove(int k) {
    int i = 1;
    while (i < n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        if (k < segTree[left]) {
            i = left;
        } else {
            k -= segTree[left];
            i = right;
        }
    }

    int ret = i - n;

    segTree[i] = 0;
    while (i > 1) {
        i /= 2;
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }

    return ret;
}


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    // fill (0 ... n - 1)
    initTree(n);

    k--;
    int kth = 0;
    int remain = n;
    cout << '<';
    FOR(i, 0, n) {
        kth += k;
        kth %= (remain--);

        cout << (kthRemove(kth) + 1);
        if (i != n - 1)
            cout << ", ";
    }
    cout << ">\n";

    return 0;
}