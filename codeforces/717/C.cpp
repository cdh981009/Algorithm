#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;
constexpr int M = 2e5 + 10;

int n;
int sum;
int arr[N];
bool dp[N][M];
bool memoi[N][M];

// 짝수를 나눠서 재귀적으로 생각하는 발상!!!

bool getDp(int ind, int s) {
    if (ind == n)
        return s == sum / 2;
    
    bool &ref = dp[ind][s];

    if (memoi[ind][s])
        return ref;
    memoi[ind][s] = true;

    ref = getDp(ind + 1, s + arr[ind]) | getDp(ind + 1, s);

    return ref;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }

    // 처음부터 good인지 확인
    // 합이 홀수거나 짝수인데 partition 불가능하면 good
    if (sum % 2 == 1 || !getDp(0, 0)) {
        cout << 0 << '\n';
    } else {
        int ind = 0;
        while (true) {
            FOR(i, 0, n) {
                if (arr[i] % 2 == 1) {
                    ind = i + 1;
                    break;
                }
                arr[i] /= 2;
            }
            if (ind != 0)
                break;
        }
        cout << 1 << '\n' << ind << '\n';
    }

    return 0;
}