#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

char str[100][51];
bool check[100];

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, len; cin >> n >> len;
    FOR(i, 0, n)
        cin >> str[i];

    int center = -1;
    vector<pair<int, int>> palindromePair;
    FOR(i, 0, n) {
        if(check[i]) continue;
        bool selfPalindrome = false;
        
        FOR(j, i, n) {
            bool palindrome = true;
            FOR(k, 0, len) {
                if (str[i][k] != str[j][len - k - 1]) {
                    palindrome = false;
                    break;
                }
            }
            if (palindrome) {
                if (i == j) {
                    selfPalindrome = true;
                } else {
                    check[i] = check[j] = true;
                    palindromePair.push_back({i, j});
                    break;
                }
            }
        }

        if (!check[i] && selfPalindrome)
            center = i;
    }

    deque<int> ans;
    if (center != -1)
        ans.push_back(center);
    for (auto pair : palindromePair) {
        ans.push_back(pair.first);
        ans.push_front(pair.second);
    }

    cout << ans.size() * len << "\n";
    for (auto ind : ans) {
        cout << str[ind];
    }
    cout << "\n";
    return 0;
}