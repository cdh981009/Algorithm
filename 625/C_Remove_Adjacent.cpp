#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;
    string str; cin >> str;
    vector<pair<int, size_t>> alphabetSort(len);
    FOR(i, 0, len)
        alphabetSort[i] = {str[i], i};
    sort(alphabetSort.rbegin(), alphabetSort.rend());

    int ans = 0;
    FOR(i, 0, len) {
        FOR(j, 0, len) {
            size_t ind = alphabetSort[j].second;
            int alph = str[ind];
            if (alph == -1) continue;
            int la, ra;
            la = ind - 1;
            ra = ind + 1;
            bool erasable = false;
            while (la >= 0) {
                if (str[la] != -1) {
                    erasable |= (str[la] == alph - 1);
                    break;
                }
                la--;
            }
            while (ra < len) {
                if (str[ra] != -1) {
                    erasable |= (str[ra] == alph - 1);
                    break;
                }
                ra++;
            }
            if (erasable) {
                ans++;
                str[ind] = -1;
                break;
            }
        }
    }
    cout << ans << endl;   

    return 0;
}