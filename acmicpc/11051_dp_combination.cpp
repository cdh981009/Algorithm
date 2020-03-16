#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for(int i=(a); i<(b); ++i)
#define FOR_(i, a, b) for(int i=(a); i<=(b); ++i)
#define MOD 10007
using namespace std;

int cache[1001][1001];

int comb(int n, int k) {
  if (n == k) return 1;
  if (k == 0) return 1;

  int &ref = cache[n][k];

  if (ref != -1) return ref;

  return ref = (comb(n - 1, k) + comb(n - 1, k - 1)) % MOD;
}

int main() {
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(int) * 1001 * 1001);
  int n, k; cin >> n >> k;
  cout << comb(n, k) << endl;
}