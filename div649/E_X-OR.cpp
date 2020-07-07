#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int n;
constexpr int BIT = 11;
vector<int> z(BIT, -1);
constexpr int N = 2048;
vector<vector<bool>> asked(N, vector<bool>(N, false));
vector<vector<int>> cache(N, vector<int>(N, -1));

int query(int x, int y) {
    if (x > y) swap(x, y);
    if (asked[x][y]) return cache[x][y];
    asked[x][y] = true;
    cout << "? " << x + 1 << " " << y + 1 << "\n";
    cout.flush();
    int get;
    cin >> get;
    return cache[x][y] = get;
}

int getValue(int ind, int preValue = (1 << BIT) - 1) {
    int val = preValue;
    for (int i = 0; i < BIT; ++i) {
        if (z[i] == ind || (preValue & (1 << i)) == 0)
            continue;
        int get = query(z[i], ind);
        val &= get;
    }
    return val;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    // bit 11개만 체크하면 된다.
    // cout.flush();

    cin >> n;
    int cnt = 0;
    while (cnt < BIT) {
        int x = rand() % n;
        int y;
        do {
            y = rand() % n;
        } while (x == y);
        int get = query(x, y);
        for (int i = 0; i < BIT; ++i) {
            if (z[i] != -1) continue;
            if ((get & (1 << i)) == 0) { // both x and y's i th bit is zero
                z[i] = x;
                cnt++;
                //cout << "found " << i << "\n";
            }
        }
    }
    //cout << "z complete" << endl;
    // z is complete;
    int ind = 0;
    int val = getValue(ind);
    for (int i = 1; i < n; ++i) {
        int get = query(i, ind);
        if ((get | val) != val)
            continue;
        ind = i;
        val = getValue(ind, val);
    }
    // now ind is zero
    vector<int> ans(n);
    for (int i = 0; i < n; ++ i)
        ans[i] = (i == ind ? 0 : query(i, ind));
    
    cout << "! ";
    for (auto a : ans)
        cout << a << " ";
    cout << "\n";
    /*
    for (auto zi : z) {
        cout << zi << " ";
    }
    cout << " \n";
    */
   cout.flush();
    return 0;
}