#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc, b; cin >> tc >> b;
    FOR_(t, 1, tc) {
        vector<int> data(b + 1);
        int sameBitInd = -1;
        int difBitInd = -1;
        int queryCnt = 1;
        int queryInd = 1;
        while (true) {
            if (queryCnt != 1 && queryCnt % 10 == 1) {
                if (sameBitInd != -1) {
                    cout << sameBitInd << "\n";
                    cout << flush;
                    int bit; cin >> bit;
                    if (bit != data[sameBitInd])
                        transform(data.begin() + 1, data.end(), data.begin() + 1, [](int v) { return !v; });
                } else {
                    cout << 1 << "\n";
                    cout << flush;
                    int bit; cin >> bit;
                }
                if (difBitInd != -1) {
                    cout << difBitInd << "\n";
                    cout << flush;
                    int bit; cin >> bit;
                    if (bit != data[difBitInd])
                        reverse(data.begin() + 1, data.end());
                } else {
                    cout << 1 << "\n";
                    cout << flush;
                    int bit; cin >> bit;
                }
            } else {
                cout << queryInd << "\n";
                cout << flush;
                bool bit1; cin >> bit1;
                cout << b - queryInd + 1 << "\n";
                cout << flush;
                bool bit2; cin >> bit2;
                if (sameBitInd == -1 && bit1 == bit2)
                    sameBitInd = queryInd;
                if (difBitInd == -1 && bit1 != bit2)
                    difBitInd = queryInd;
                data[queryInd] = bit1;
                data[b - queryInd + 1] = bit2;
                if (queryInd++ >= (b + 1)/2)
                    break;
            }
            queryCnt += 2;
        }
        FOR_(i, 1, b) 
            cout << data[i];
        cout << "\n";
        cout << flush;
        char res; cin >> res;
        if (res == 'N') break;
    }
    return 0;
}