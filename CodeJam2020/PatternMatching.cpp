#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define FOR_(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    FOR_(t, 1, tc) {
        int n; cin >> n;
        deque<char> prefix;
        deque<char> suffix;
        string middle = "";
        bool possible = true;
        FOR(i, 0, n) {
            string str; cin >> str;
            if (!possible) continue;
            deque<char> v(str.begin(), str.end());
            if (str.front() != '*') {
                //cout << "pref" << endl;
                int ind = 0;
                while(!v.empty() && v.front() != '*') {
                    if (prefix.size() > ind && prefix[ind] != v.front()) {
                        possible = false;
                        break;
                    } else if (prefix.size() <= ind) {
                        prefix.push_back(v.front());
                    }
                    ind++;
                    v.pop_front();
                }
            }
            if (str.back() != '*') {
                //cout << "suff" << endl;
                int ind = 0;
                while(!v.empty() && v.back() != '*') {
                    //cout << v.back() << endl;
                    if (suffix.size() > ind && suffix[suffix.size() - ind - 1] != v.back()) {
                        possible = false;
                        break;
                    } else if (suffix.size() <= ind) {
                        suffix.push_front(v.back());
                    }
                    ind++;
                    v.pop_back();
                }
            }
            // 나머지
            FOR(j, 0, v.size())
                if (v[j] != '*')
                    middle.push_back(v[j]);
        }
        string output = "";
        FOR(i, 0, prefix.size())
            output.push_back(prefix[i]);
        output.append(middle);
        FOR(i, 0, suffix.size())
            output.push_back(suffix[i]);
            
        cout << "Case #" << t << ": " << (possible ? output : "*") << "\n";
    }
    return 0;
}