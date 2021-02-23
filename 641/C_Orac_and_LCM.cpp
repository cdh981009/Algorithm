#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)
#define INF 987654321

constexpr int N = (int)2e5;
int minFactor[N + 1];
int primeCnt = 0;
vector<vector<int>> factorsCnt;
vector<int> indToPrime;
int primeToInd[N + 1];

void init() {
    FOR_(i, 0, N)
        minFactor[i] = i;
    for (int i = 2; i * i <= N; ++i) {
        if (minFactor[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (minFactor[j] == j)
                    minFactor[j] = i;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (minFactor[i] == i) {
            primeToInd[i] = primeCnt;
            primeCnt++;
            indToPrime.push_back(i);
        }
    }

    factorsCnt.assign(primeCnt, vector<int>(31, 0));
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    init();

    int n; cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        map<int, int> divCnt;
        while (x > 1) {
            divCnt[minFactor[x]]++;
            x /= minFactor[x];
        }
        for (auto p : divCnt) {
            // cout << p.first << " " << p.second << endl;
            factorsCnt[primeToInd[p.first]][p.second]++;
        }
        // cout << "\n" << endl;
    }
    long long ans = 1;
    FOR(i, 0, factorsCnt.size()) {
        int cnt = 0;
        for(int j = 30; j >= 1; --j) {
            cnt += factorsCnt[i][j];
            if (cnt >= n - 1) {
                ans *= pow(indToPrime[i], j);
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}