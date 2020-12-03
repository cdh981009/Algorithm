// 5977: Mowing the Lawn
// https://www.acmicpc.net/problem/5977
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<long long> expireList(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    // deq[0] is always maximum value
    // keep deq in descending order
    deque<long long> deq;

    deq.push_back(arr[0]);
    deq.push_back(0);
    expireList[k] = arr[0];
    if (k + 1 < n)
        expireList[k + 1] = 0;

    long long sum = 0;
    FOR(i, 1, n) {
        // i-th stage

        // 1. insert
        long long newNum = deq.front() - arr[i];
        while (!deq.empty() && deq.back() < newNum) {
            deq.pop_back();
        }
        deq.push_back(newNum);

        if (i + k + 1 < n)
            expireList[i + k + 1] = newNum;

        // 2. delete
        if (i >= k) {
            if (!deq.empty() && deq.front() == expireList[i])
                deq.pop_front();
        }

        sum += arr[i];
    }

    cout << deq.front() + sum << '\n';

    return 0;
}