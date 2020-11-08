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

int main() {
    freopen("input.txt", "r", stdin);
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

    return 0;
}