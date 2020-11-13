// 2809: POPLOČAVANJE
// https://www.acmicpc.net/problem/2809
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

// fuck you Aho-Corasick and fuck you out of memory
// I'm going suffix-array

struct comp {
    const vector<int>& group;
    int t;

    comp(const vector<int>& _g, int _t) : group(_g), t(_t) {}

    bool operator()(int a, int b) {
        return (group[a] == group[b]) ? (group[a + t] < group[b + t]) : (group[a] < group[b]);
    }
};

vector<int> getSuffixArray(const string& str) {
    int n = str.size();
    int t = 1;
    
    vector<int> group(n + 1);
    vector<int> newGroup(n + 1);
    
    group[n] = -1;
    newGroup[n] = -1;

    FOR(i, 0, n) {
        group[i] = str[i];
    }

    vector<int> perm(n);
    FOR(i, 0, n) {
        perm[i] = i;
    }

    while (true) {
        auto compareUsing2T = comp(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);

        //
        t *= 2;
        if (t >= n)
            break;
        //

        newGroup[perm[0]] = 0;
        FOR(i, 1, n) {
            if (compareUsing2T(perm[i - 1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        }

        swap(group, newGroup);
    }

    return perm;
}

// if return -1, fail to find the needle
// else, return x that haystack[x... (x + needle.size() - 1)] == needle

vector<int> tile;
void findNeedle(const string& haystack, const string& needle, const vector<int>& suffixArray) {
    auto s = suffixArray.begin();
    auto e = suffixArray.end();

    int i = 0;
    // O(needle.size() * log(haystack.size())
    for (; i < needle.size(); ++i) {
        s = lower_bound(s, e, needle[i], [&](const int& a, const char& c) -> bool { 
            return a + i < haystack.size() ? haystack[a + i] < c : true;
        });

        e = upper_bound(s, e, needle[i], [&](const char& c, const int& a) -> bool {
            return a + i < haystack.size() ? c < haystack[a + i] : false;
        });

        //int sd = s - suffixArray.begin();
        //int ed = e - suffixArray.begin();

        if (s >= e) {
            break;
        }
    }

    if (i == needle.size()) {
        vector<int> ret;
        while (s != e) {
            tile[*s] += 1;
            tile[*s + needle.size()] -= 1;
            s++;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string haystack;
    cin >> haystack;

    auto suffixArray = getSuffixArray(haystack);

    tile = vector<int> (n + 1, 0);
    int m; cin >> m;
    FOR(i, 0, m) {
        string needle; cin >> needle;
        findNeedle(haystack, needle, suffixArray);
    }

    long long cnt = 0;
    int ans = 0;
    FOR(i, 0, n) {
        cnt += tile[i];
        ans += (cnt == 0);
    }

    cout << ans << '\n';

    return 0;
}