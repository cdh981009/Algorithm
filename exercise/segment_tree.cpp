#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
constexpr int N = 1 << 20;
int n;
int segTree[N];

int sum(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += segTree[a++];
        if (b%2 == 0) s += segTree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void update(int ind, int val) {
    ind += n;
    segTree[ind] = val;
    while (ind > 1) {
        ind /= 2;
        segTree[ind] = segTree[2*ind] + segTree[2*ind + 1];
    }
}

inline int power2RoundUp(int x) {
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x++;
    return x;
}

void init(const vector<int>& v) {
    n = power2RoundUp(v.size());
    cout << "size is: " << n << endl;
    for (int i = 0; i < n; ++i)
        segTree[n + i] = (i < v.size() ? v[i] : 0); 
    for (int i = n - 1; i > 0; --i) 
        segTree[i] = segTree[2*i] + segTree[2*i + 1];
}

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

    init(arr);
    cout << "init complete" << endl;
    cout << sum(0, 0) << endl;
    cout << sum(0, 3) << endl;
    return 0;
}