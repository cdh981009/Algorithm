// 7626: 직사각형
// https://www.acmicpc.net/problem/7626
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = (1 << 20);
constexpr int M = 1e9 + 7;
int n;
// 1-based array
struct interval {
    int cnt = 0; // 이 노드를 완전히 덮는 선분이 몇개 있는지 
    int len = 0; // 이 노드의 범위에서 현재 존재하는 선의 길이
    int fullLen = 0;
} segTree[N];

vector<int> cy;
vector<int>::iterator u;

struct line {
    int x;
    int y1;
    int y2;
    bool start;
    int yInd1;
    int yInd2;
};

void update(int value, int a, int b, int l, int r, int n) {
    if (b < l || a > r)
        return;
    
    auto& node = segTree[n];
    
    if (l == r) {
        node.cnt += value;
        node.len = node.fullLen * (node.cnt > 0);

        return;
    }

    if (a <= l && r <= b) {
        // 선분이 현재 노드가 의미하는 범위를 완전히 덮는 경우
        node.cnt += value;
    } else {
        int m = (l + r) / 2;
        update(value, a, b, l, m, n * 2);
        update(value, a, b, m + 1, r, n * 2 + 1);
    }

    node.len = (node.cnt > 0) ? node.fullLen :
        (segTree[2 * n].len + segTree[2 * n + 1].len);

    return;
}

void update(const line& l) {
    update(l.start ? +1 : -1, l.yInd1, l.yInd2 - 1, 0, n - 1, 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<line> lines;
    lines.reserve(2 * n);
    cy.reserve(2 * n);

    FOR(i, 0, n) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        lines.push_back({x1, y1, y2, true});
        lines.push_back({x2, y1, y2, false});
        cy.push_back(y1);
        cy.push_back(y2);
    }

    // 1. 모든 y좌표에 대해 정렬 후 좌표압축을 한다
    sort(cy.begin(), cy.end());
    u = unique(cy.begin(), cy.end());

    // yi가 출발점이고 yj가 도착점이면 그 범위는 [i, j - 1]이다
    for (auto& l : lines) {
        l.yInd1 = lower_bound(cy.begin(), u, l.y1) - cy.begin();
        l.yInd2 = lower_bound(cy.begin(), u, l.y2) - cy.begin();
    }
    
    // init tree
    int s = u - cy.begin() - 1;
    for (::n = 1; ::n < s; ::n <<= 1)
        ;
    for (int i = 0; i < ::n; ++i) {
        segTree[i + ::n].fullLen = (i < s ? cy[i + 1] - cy[i] : 0 /*default vaule*/);
    }
    for (int i = ::n - 1; i >= 1; --i) {
        segTree[i].fullLen = segTree[2 * i].fullLen + segTree[2 * i + 1].fullLen;
    }

    // 2. 모든 x좌표에 대해 정렬
    sort(lines.begin(), lines.end(), [](const line& l, const line& r) {
        return l.x < r.x;
    });

    // 3. 스위핑. (delta x) * (현재 선들의 길이) 만큼 넓이를 더해주고 선들의 길이를 업데이트 한다
    // 직사각형이 시작하는 선분이면 선들의 길이에 추가해주고
    // 직사각형이 닫히는 선분이면 선들의 길이에서 빼준다
    long long area = 0;
    int prevX = 0;
    for (auto& l : lines) {
        int width = l.x - prevX;
        area += (long long)segTree[1].len * width;

        update(l);
        prevX = l.x;
    }

    cout << area << "\n";

    return 0;
}