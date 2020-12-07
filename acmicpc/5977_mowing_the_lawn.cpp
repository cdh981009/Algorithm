// 5977: Mowing the Lawn
// https://www.acmicpc.net/problem/5977
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// 문제: 주어진 수열에서 최대 k개 만큼 연속으로 고를 수 있을 때 고른 숫자의 합의 최대값

/*
// 풀이:
// dp[x][y]: dp[0... x-1] 까지 구했다 하고, ind x에서 y번 연속으로 수를 골랐을 때 합의 최댓값
//
// 1)
// 점화식을 생각해보면
// if y == 0:
//      dp[x][0] = max(dp[x-1][0...k])
// else:
//      dp[x][y] = dp[x - 1][y - 1] + val[x];
//
// 관찰하면
// [x][0]: 전 식들의 최대값
// [x][1 ~ k]: 왼쪽 위 값([x-1][y-1])에서 val[x] 만큼 증가된다
//
// 2)
// x 가 1 증가 할 때마다
// i.   기존 수들 중 최대값이 새로 들어오고,
// ii.  k번째 수는 나가며,
// iii. 나머지 수들은 val[x] 만큼 커지는
// 숫자들의 모임이라고 생각하자
// 
// 3)
// 숫자들의 모임을 deq에서 관리 하되 최대값을 O(1)만에 구할 수 있게 정렬해 관리한다.
// 어떤 값이 모임에 새로 들어 올 때, deq에 그 보다 작은 값들이 있다면 그 값들은 새로 들어온 값이
// 나가기 전에 나가므로, 최대값이 될 가능성이 없다. 따라서 deq에서 완전 제외해도 된다
// 나머지 수들이 val[x] 만큼 커지는 것은 update 하기 오래 걸리므로 나중에 모아놓았다가
// 마지막에 한거번에 update 한다.
*/

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