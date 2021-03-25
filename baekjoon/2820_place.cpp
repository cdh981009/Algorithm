// 2820: PLAĆE
// https://www.acmicpc.net/problem/2820
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 20);

int n, m;

vector<int> wage;
vector<vector<int>> children;

vector<int> subEnd;
vector<int> perm;

vector<int> reverseIndex;

// 차이배열에 대한 seg tree
// point update 통해 개념적 range update 수행
// 누적 합 range query 통해 개념적 point query 수행
int segTree[N];

void initTree(const vector<int>& arr) {
    for (n = 1; n < arr.size(); n <<= 1)
        ;
    for (int i = 0; i < n; ++i) {
        segTree[i + n] = (i < arr.size() ? arr[i] : 0 /*default vaule*/);
    }
    for (int i = n - 1; i >= 1; --i) {
        segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
    }
}

void pointUpdate(int ind, int val) {
    ind += n;
    segTree[ind] += val;
    while (ind > 1) {
        ind >>= 1;
        segTree[ind] = segTree[2 * ind] + segTree[2 * ind + 1];
    }
}

int rangeQuery(int a, int b) {
    a += n;
    b += n;
    int sum = 0;
    while (a <= b) {
        if (a % 2 == 1) // odd
            sum += segTree[a++];
        if (b % 2 == 0) // even
            sum += segTree[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}

void computeSubEnd(int node) {
    reverseIndex[node] = perm.size();
    perm.push_back(node);

    for (auto child : children[node]) {
        computeSubEnd(child);
    }

    subEnd[node] = perm.size() - 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    wage = vector<int>(n, 0);
    children = vector<vector<int>>(n);

    cin >> m;
    cin >> wage[0];

    FOR(i, 1, n) {
        cin >> wage[i];
        int p; cin >> p; p--;
        children[p].push_back(i);
    }

    reverseIndex = vector<int>(n);
    subEnd = vector<int>(n, 0);
    perm.reserve(n);
    computeSubEnd(0);
    
    //difference array, sorted in permutation
    vector<int> diff(n, 0);
    diff[0] = wage[0];
    FOR(i, 1, n) {
        diff[i] = wage[perm[i]] - wage[perm[i - 1]];
    }

    initTree(diff);

    // query
    FOR(i, 0, m) {
        char type; cin >> type;

        if (type == 'p') {
            int emp; cin >> emp; emp--;
            int val; cin >> val;

            int start = reverseIndex[emp] + 1;
            int end = subEnd[emp] + 1;

            if (start < n)
                pointUpdate(start, val);
            if (end < n)
                pointUpdate(end, -val);
        } else {
            int x; cin >> x;
            x--;
            x = reverseIndex[x];
            cout << rangeQuery(0, x) << '\n';
        }
    }

    return 0;
}