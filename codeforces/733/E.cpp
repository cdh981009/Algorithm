#include <bits/stdc++.h>

using namespace std;

#define INF 1e9;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

constexpr int N = 20101;
string str;
int cnt[27];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        cin >> str;
        string ans;
        ans.reserve(str.size());
        memset(cnt, 0, sizeof(int) * 27);
        int minCnt = 1e7;
        int cntcnt = 0;
        FOR(i, 0, str.size()) {
            int c = str[i] - 'a';
            cnt[c]++;
        }

        int third;
        FOR(i, 0, 27) {
            if (cnt[i] > 0) {
                cntcnt++;
                minCnt = min(minCnt, cnt[i]);
                if (cntcnt == 3) {
                    third = i;
                }
            }
        }
        
        if (cntcnt == 1) {
            ans = str;
        } else if (minCnt == 1) {
            int c;
            FOR(i, 0, 27) {
                if (cnt[i] == 1) {
                    c = i;
                    break;
                }
            }
            ans.push_back(c + 'a');
            FOR(i, 0, 27) {
                if (i == c)
                    continue;
                FOR(j, 0, cnt[i]) {
                    ans.push_back(i + 'a');
                }
            }
        } else {
            int c;
            FOR(i, 0, 27) {
                if (cnt[i] > 0) {
                    c = i;
                    break;
                }
            }
            int n = str.size() - cnt[c];
            if (cnt[c] > n + 2) {
                if (cntcnt == 2) {
                    ans.push_back(c + 'a');
                    cnt[c]--;
                    FOR(i, 0, 27) {
                        if (i == c || cnt[i] == 0)
                            continue;
                        FOR(j, 0, cnt[i]) {
                            ans.push_back(i + 'a');
                        }
                    }
                    while (cnt[c] > 0) {
                        ans.push_back(c + 'a');
                        cnt[c]--;
                    }
                } else {
                    // 2번째 글자가 바뀌는 순간 욱겨넣기
                    ans.push_back(c + 'a');
                    cnt[c]--;
                    bool first = true;
                    FOR(i, 0, 27) {
                        if (i == c || cnt[i] == 0)
                            continue;
                        FOR(j, 0, cnt[i]) {
                            ans.push_back(i + 'a');
                            if (first) {
                                first = false;
                                while (cnt[c] > 0) {
                                    ans.push_back(c + 'a');
                                    cnt[c]--;
                                }
                                ans.push_back(third + 'a');
                                cnt[third]--;
                            }
                        }
                    }
                }
            } else {
                // 슉슉넣기
                ans.push_back(c + 'a');
                ans.push_back(c + 'a');

                cnt[c] -= 2;

                FOR(i, 0, 27) {
                    if (i == c)
                        continue;
                    FOR(j, 0, cnt[i]) {
                        ans.push_back(i + 'a');
                        if (cnt[c] > 0) {
                            ans.push_back(c + 'a');
                            cnt[c]--;
                        }
                    }
                }
            }

        }
        cout << ans << '\n';
    }
    return 0;
}