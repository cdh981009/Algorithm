#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 110;
constexpr int M = 50;

int n;
string arr[N];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        int ans = 0;
        cin >> n;
        FOR(i, 0, n) {
            cin >> arr[i];
            if (i > 0) {
                string x = arr[i];
                if (x.size() > arr[i - 1].size())
                    continue;
                
                int common = 0;
                FOR(j, 0, x.size()) {
                    if (arr[i - 1][j] == x[j]) {
                        common++;
                    } else if (arr[i - 1][j] < x[j]) {
                        // 남은거에 0 붙힘
                        while (x.size() < arr[i - 1].size()) {
                            x.push_back('0');
                        }
                        break;
                    } else {
                        // 크기가 하나 더 커질 때 까지 0 붙힘
                        while (x.size() <= arr[i - 1].size()) {
                            x.push_back('0');
                        }
                        break;
                    }
                }

                if (common == x.size()) {
                    if (x.size() == arr[i - 1].size()) {
                        x.push_back('0');
                    } else {
                        bool allNine = true;
                        while (x.size() < arr[i - 1].size()) {
                            if (arr[i - 1][x.size()] != '9') {
                                allNine = false;
                            }
                            x.push_back(arr[i - 1][x.size()]);
                        }
                        if (allNine) {
                            x = arr[i];
                            while (x.size() <= arr[i - 1].size()) {
                                x.push_back('0');
                            }
                        } else {
                            bool carry = true;
                            for (int j = x.size() - 1; carry; --j) {
                                if (carry) {
                                    if (x[j] == '9') {
                                        x[j] = '0';
                                    } else {
                                        x[j] += 1;
                                        carry = false;
                                    }
                                }
                            }
                        }
                    }
                }

                ans += x.size() - arr[i].size();
                arr[i] = x;
            }
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
        // FOR(i, 0, n) {
        //     cout << arr[i] << '\n';
        // }
    }

    return 0;
}