#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int m;
constexpr int N = 60;
constexpr int M = 499;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        long long ans = 0;
        long long sum = 0;

        vector<long long> cards;
        vector<int> primes;
        cin >> m;

        FOR(i, 0, m) {
            int p;
            long long n;
            cin >> p >> n;

            primes.push_back(p);
            cards.push_back(n);

            sum += p * n;
        }

        int X = N * M;

        for (long long i = sum - 1; i >= sum - X; --i) {
            long long aux = sum;
            long long target = i;
            bool possible = true;
            // target number is i

            int ind = 0;
            while (target > 1 && ind < primes.size()) {
                int cnt = 0;
                int p = primes[ind];

                while (target % p == 0) {
                    cnt++;
                    target /= p;
                }

                if (cnt > cards[ind]) {
                    possible = false;
                    break;
                } else {
                    aux -= p * cnt;
                }

                ind++;
            }

            if (target != 1)
                possible = false;

            if (possible && aux == i) {
                ans = i;
                break;
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}