#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tc; cin >> tc;
    while(tc--) {
        string q; cin >> q;
        int n; cin >> n;
        string str; cin >> str;
        regex num("[0-9]+");
        sregex_iterator it(str.begin(), str.end(), num); sregex_iterator end;
        deque<int> vec;
        while (it != end) {
            smatch m = *it++;
            vec.push_back(stoi(m.str(0)));
        }

        bool reversed = false;
        bool err = false;
        FOR(i, 0, q.length()) {
            if (q[i] == 'R') {
                reversed = !reversed;
            } else {
                if (vec.size() == 0) {
                    err = true;
                    break;
                } else if (reversed) {
                    vec.pop_back();
                } else {
                    vec.pop_front();
                }
            }
        }
        if (err) {
            cout << "error\n";
        } else {
            cout << "[";
            FOR(i, 0, vec.size())
                cout << vec[reversed ? vec.size() - 1 - i : i] << (i == vec.size() - 1 ? "" : ",");
            cout << "]\n";
        }
    }
    return 0;
}