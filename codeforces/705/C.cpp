#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5001;

int n, k;
string s;
int cnt[26];

// i번째 글자를 c로 바꾸면 beautiful하게 할 수 있나?
bool solve(int i, char c) {
    cnt[c - 'a']++;
    bool ret = false;

    int remainLen = n - i - 1;
    
    for (int i = 0; i < 26; ++i) {
        remainLen -= (k - cnt[i] % k) % k;
    }

    cnt[c - 'a']--;
    ret = remainLen >= 0 && remainLen % k == 0;

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        memset(cnt, 0, sizeof(int) * 26);
        cin >> n >> k >> s;
        
        bool possible = (n % k == 0);
        string ans;

        if (!possible) {
            cout << -1 << '\n';
        } else {
            int ansi;
            char ansj;

            for (int i = 0; i < n; ++i) {
                for (char j = 'z'; j > s[i]; --j) {
                    if (solve(i, j)) {
                        ansi = i;
                        ansj = j;
                    }
                }
                cnt[s[i] - 'a']++;
            }

            // self
            int tmp = 0;
            for (int i = 0; i < 26; ++i) {
                tmp -= (k - cnt[i] % k) % k;
            }
            if (tmp == 0) {
                ansi = n - 1;
                ansj = s[n - 1];
            }

            //cout << ansi << " " << ansj << '\n';

            memset(cnt, 0, sizeof(int) * 26);
            // construct answer
            int remainLen = n - ansi - 1;
            for (int i = 0; i < ansi; ++i) {
                cnt[s[i] - 'a']++;
                cout << s[i];
            }
            cnt[ansj - 'a']++;
            cout << ansj;
            for (int i = 0; i < 26; ++i) {
                remainLen -= (k - cnt[i] % k) % k;
            }

            for (int i = 0; i < remainLen; ++i) {
                cout << 'a';
            }

            for (int i = 0; i < 26; ++i) {
                for (int j = (k - cnt[i] % k) % k; j > 0; --j) {
                    cout << (char)('a' + i);
                }
            }

            cout << '\n';
        }
    }
    return 0;
}