// 9248: Suffix Array
// https://www.acmicpc.net/problem/9248
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _g, int _t) : group(_g), t(_t) {}

    bool operator()(int a, int b) {
        if (group[a] != group[b])
            return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vector<int> getSuffixArray(const string& s) {
    int n = s.size();
    int t = 1;
    // t = 1 일땐 실제로 정렬하지 않고 group만 정해놓는다
    vector<int> group(n + 1);
    vector<int> newGroup(n + 1);
    group[n] = newGroup[n] = -1;
    FOR(i, 0, n)
    group[i] = s[i];

    vector<int> perm(n);
    FOR(i, 0, n)
    perm[i] = i;

    // 처음 2, 4, 8, 16.. 개의 문자를 이용해 반복해서 정렬한다
    while (true) {
        // 처음 t개의 문자에 대해 정렬된 정보가 있을 때
        // 처음 2 * t개의 문자를 이용해 재정렬한다
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);

        t *= 2;
        // 이번에 정렬한 t가 n보다 크다
        if (t >= n)
            break;

        newGroup[perm[0]] = 0;
        FOR(i, 1, n) {
            if (compareUsing2T(perm[i - 1], perm[i])) {
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            } else {
                newGroup[perm[i]] = newGroup[perm[i - 1]];
            }
        }
        swap(group, newGroup);
    }

    return perm;
}

vector<int> getLCP(const string& s, const vector<int>& suffixArray) {
    // string2SuffixArray[x] = y: s[x]에서 시작하는 접미사는 suffixArray[y]에 있다.
    // <-> suffixArray[y] = x;
    vector<int> string2SuffixArray(s.size());
    FOR(i, 0, s.size()) {
        string2SuffixArray[suffixArray[i]] = i;
    }

    vector<int> lcp(s.size(), 0);

    // lcp를 접미사의 길이 내림차순으로 계산한다.
    // 길이가 l인 접미사의 lcp값이 x 라면
    // 길이가 l - 1인 접미사의 lcp 값은 최소 x - 1이라는 것을 알 수 있다.
    // 따라서 x번째 문자부터 비교하면 된다
    // = O(n)
    auto commonPrefix = [&](int ind) {
        int x = string2SuffixArray[ind];

        if (x == 0) // suffix array 상에서 제일 앞에 온다
            return 0;

        int i = suffixArray[x]; // i == ind
        int j = suffixArray[x - 1];
        int k = 0;

        if (ind != 0) // 가장 긴 접미사가 아닐 때 (미리 알고있는 정보가 있다)
            k = max(0, lcp[string2SuffixArray[i - 1]] - 1);

        while (i + k < s.size() && j + k < s.size() && s[i + k] == s[j + k]) {
            k++;
        }

        return k;
    };

    for (int i = 0; i < s.size(); ++i) {
        lcp[string2SuffixArray[i]] = commonPrefix(i);
    }

    return lcp;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    auto suffixArray = getSuffixArray(s);
    for (const auto& i : suffixArray) {
        cout << i + 1 << ' ';
    }
    cout << '\n';

    auto lcp = getLCP(s, suffixArray);
    cout << "x ";
    FOR(i, 1, lcp.size()) {
        cout << lcp[i] << ' ';
    }
    cout << "\n";

    return 0;
}