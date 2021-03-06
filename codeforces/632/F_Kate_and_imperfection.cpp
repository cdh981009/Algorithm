#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = (int)5e5;
int minFactor[N+1];
int primeCnt[N+1];
vector<int> prime;

void sieve() {
    FOR(i, 0, N+1)
        minFactor[i] = i;
    for (int i = 2; i * i <= N; ++i) {
        if (minFactor[i] != i) continue;
        for (int j = i * i; j <= N; j += i) {
            if (minFactor[j] == j)
                minFactor[j] = i;
        }
    }
    int pCnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (minFactor[i] == i) {
            primeCnt[i] = ++pCnt;
            prime.push_back(i);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int n; cin >> n;
    if (n <= 3) {
        FOR(i, 0, n-1)
            cout << 1 << " ";
        cout << "\n";
    } else {
        vector<int> ans(n+1, 0);
        int pCnt = 0;
        FOR_(i, 1, n) {
            if (minFactor[i] == i)
                pCnt++;
        }
        //cout << pCnt << endl;
        fill_n(ans.begin() + 1, pCnt, 1);
        int num = 2;
        int ind = pCnt + 1;
        while (ind < ans.size()) {
            int fillNum = primeCnt[minFactor[num]];
            //cout << "num : " << num << " minFactor " << minFactor[num] << " primeCnt " << primeCnt[minFactor[num]] << endl;
            for (int i = 0; ind < ans.size() && i < fillNum; ++i) {
                if ((long long)prime[i] * num > n)
                    break;
                ans[ind++] = num;
            }
            num++;
        }
        FOR_(i, 2, n) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}