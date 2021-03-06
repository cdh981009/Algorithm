#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

#define T (~0)

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    vector<int> vec;
    while (len--) {
        int n; cin >> n;
        vec.push_back(n);
    }
    vector<int> prefixAnd(vec.size());
    vector<int> postfixAnd(vec.size());
    int preAcc = T;
    int postAcc = T;
    FOR(i, 0, vec.size()) {
        prefixAnd[i] = (preAcc &= ~vec[i]);
        int n = vec.size() - i - 1;
        postfixAnd[n] = (postAcc &= ~vec[n]);
    }
    int maxIndex = 0;
    int maxVal = -1;
    FOR(i, 0, vec.size()) {
        int base = (i == 0 ? T : prefixAnd[i - 1]) & (i == vec.size() - 1 ? T : postfixAnd[i + 1]);
        int val = (base & vec[i]);
        if (val > maxVal) {
            maxVal = val;
            maxIndex = i;
        }
    }
    cout << vec[maxIndex] << " ";
    FOR(i, 0, vec.size()) {
        if (i == maxIndex) continue;
        cout << vec[i] << " ";
    }
    cout << "\n";
    return 0;
}