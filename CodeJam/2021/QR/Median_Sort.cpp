#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 50;

int t, n, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n >> q;
    while (t--) {
        vector<int> arr;
        // sending queries
        int med;
        
        // init
        cout << "1 2 3" << endl;
        cin >> med;
        if (med == 1) {
            arr = {2, 1, 3};
        } else if (med == 2) {
            arr = {1, 2, 3};
        } else {
            arr = {1, 3, 2};
        }

        // ternary search
        FOR_(i, 4, n) {
            int l = 0;
            int r = arr.size() - 1;

            while (true) {
                int p1 = (r + 2 * l) / 3;
                int p2 = (2 * r + l) / 3;
                if (p1 == p2) {
                    p1 = l;
                    p2 = r;
                }
                cout << arr[p1] << ' ' << i << ' ' << arr[p2] << endl; 
                cin >> med;

                if (med == -1) {
                    break;
                }

                if (med == i) {
                    // middle
                    if (p1 + 1 == p2) {
                        arr.insert(arr.begin() + p2, i);
                        break;
                    } else {
                        // shorten searching range
                        l = p1;
                        r = p2;
                    }
                } else if (med == arr[p1]) {
                    if (p1 == 0) {
                        arr.insert(arr.begin(), i);
                        break;
                    } else {
                        r = p1;
                    }
                } else if (med == arr[p2]) {
                    if (p2 == arr.size() - 1) {
                        arr.push_back(i);
                        break;
                    } else {
                        l = p2;
                    }
                }
            }

            if (med == -1)
                break;
        }

        if (med == -1)
            break;

        // output answer
        FOR(i, 0, n) {
            cout << arr[i] << ' ';
        }
        cout << endl;

        int correct;
        cin >> correct;
        if (correct == -1)
            break;
    }

    return 0;
}