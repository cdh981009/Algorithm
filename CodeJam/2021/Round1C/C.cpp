#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 18);

int n;
string s, e;
int x, y;
bool visited[N];

int toNum(const string& str) {
    int ret = 0;
    FOR(i, 0, str.size()) {
        int b = (str[i] == '1');
        ret *= 2;
        ret += b;
    }
    
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR_(caseNum, 1, tc) {
        int ans = -1;

        cin >> s >> e;
        x = toNum(s);
        y = toNum(e);

        memset(visited, false, sizeof(bool) * N);

        queue<pair<int, int>> q;
        visited[x] = true;
        q.push({x, 0});
        while (!q.empty()) {
            auto& p = q.front();
            int curr = p.first;
            int dist = p.second;
            q.pop();

            if (curr == y) {
                ans = dist;
                break;
            }

            int d = curr << 1;
            int i = 20;
            while (i > 0) {
                if ((1 << i) & curr)
                    break;
                i--;
            }
            i = (1 << (i + 1)) - 1;
            int n = (curr ^ i);

            if (d < N && !visited[d]) {
                visited[d] = true;
                q.push({d, dist + 1});
            }

            if (!visited[n]) {
                visited[n] = true;
                q.push({n, dist + 1});
            }
        }

        cout << "Case #" << caseNum << ": ";
        if (ans == -1) {
            cout << "IMPOSSIBLE";
        } else {
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}