#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define INF 987654321

constexpr int N = 1 << 20;
int n;
int maxTree[N];
int minTree[N];
vector<int> m;

int getMax(int a, int b) {
    a += n; b += n;
    int s = -1;
    while (a <= b) {
        if (a%2 == 1) s = max(s, maxTree[a++]);
        if (b%2 == 0) s = max(s, maxTree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int getMin(int a, int b) {
    a += n; b += n;
    int s = m.size();
    while (a <= b) {
        if (a%2 == 1) s = min(s, minTree[a++]);
        if (b%2 == 0) s = min(s, minTree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

void update(int ind, int val) {
    ind += n;
    minTree[ind] = maxTree[ind] = val;
    while (ind > 1) {
        ind /= 2;
        maxTree[ind] = max(maxTree[2*ind], maxTree[2*ind + 1]);
        minTree[ind] = min(minTree[2*ind], minTree[2*ind + 1]);
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

void init(size_t s) {
    n = power2RoundUp(s);
    for (int i = 2*n - 1; i > 0; --i) {
        minTree[i] = s;
        maxTree[i] = -1;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<pair<int, int>> sorted;
    int len; cin >> len; 
    m.resize(len, 0);
    sorted.resize(m.size(), {0, 0});
    FOR(i, 0, m.size()) {
        int x; cin >> x;
        m[i] = x;
        sorted[i] = {m[i], i};
    }
    sort(sorted.begin(), sorted.end());
    init(m.size());

    vector<long long> ascSum(m.size(), 0);
    vector<long long> descSum(m.size(), 0);
    vector<int> ascPrev(m.size(), 0);
    vector<int> descPrev(m.size(), 0);

    FOR(i, 0, m.size()) {
        int currInd = sorted[i].second;
        int currVal = sorted[i].first;
        int prevInd;
        prevInd = getMax(0, currInd - 1);
        ascSum[currInd] = (prevInd >= 0 ? ascSum[prevInd] : 0) + (long long)(currInd - prevInd) * currVal;
        ascPrev[currInd] = prevInd;

        prevInd = getMin(currInd + 1, m.size()-1);
        descSum[currInd] = (prevInd < m.size() ? descSum[prevInd] : 0) + (long long)(prevInd - currInd) * currVal;
        descPrev[currInd] = prevInd;

        update(currInd, currInd);
    }

    int pivot = 0;
    long long maxSum = LONG_LONG_MIN;
    FOR(i, 0, m.size()) {
        long long sum = ascSum[i] + descSum[i] - m[i];
        if (sum > maxSum) {
            pivot = i;
            maxSum = sum;
        }
    }

    vector<int> log;
    int curr = pivot;
    while (curr != -1) {
        int next = ascPrev[curr];
        FOR(i, 0, curr - next) {
            log.push_back(m[curr]);
        }
        curr = next;
    }
    FOR(i, 0, log.size() - 1)
        cout << log[log.size()-1-i] << " ";
    curr = pivot;
    log.clear();
    while (curr != m.size()) {
        int next = descPrev[curr];
        FOR(i, 0, next - curr) {
            log.push_back(m[curr]);
        }
        curr = next;
    }
    FOR(i, 0, log.size())
        cout << log[i] << " ";
    cout << "\n";

    return 0;
}