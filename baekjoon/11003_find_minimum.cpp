// 11003: 최솟값 찾기
// https://www.acmicpc.net/problem/11003
#include <bits/stdc++.h>

using namespace std;

#define INF (1e9 + 5)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    // deq[0] is always minimum value
    // keep deq in ascending order

    vector<int> vec;
    vec.reserve(n);
    int front = 0;
    FOR(i, 0, n) {
        // num that comes in
        while (vec.size() > front && arr[i] < vec.back()) {
            vec.pop_back();
        }
        vec.push_back(arr[i]);
        // num that drops out
        if (i >= l && arr[i - l] == vec[front]) {
            front++;
        }
        cout << vec[front] << ' ';
    }
    cout << '\n';

    return 0;
}