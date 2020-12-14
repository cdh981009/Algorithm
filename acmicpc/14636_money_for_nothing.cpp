// 14636: Money for Nothing
// https://www.acmicpc.net/problem/14636
#include <bits/stdc++.h>

using namespace std;

#define INF INT64_MAX
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

constexpr int N = 5e5 + 1;
int n, m;

using pii = pair<int, int>;

vector<pii> pTemp;
vector<pii> cTemp;
vector<pii> producer;
vector<pii> consumer;

long long maxVal = 0;

/*
// ans[i]: i번째 producer와 계약했을 때 벌 수 있는 최대 가격
// 답 : max(ans[i]) for (0 <= i < n)
// 
// ans[i] = max((e[j] - d[i]) * (q[j] - p[i])) for all j that p[i] < q[j]
//
// p[i]를 기준으로 p[i]는 증가하고 d[i]는 감소하게 정렬
// e[i]를 기준으로 q[i]는 증가하고 e[i]는 감소하게 정렬
*/

void work(int s, int e, int p, int q) {
    int mid = (s + e) / 2;

    long long ans = -INF;
    int opt = q;

    FOR_(k, p, q) {
        if (consumer[k].second - producer[mid].second < 0)
            continue;
        long long res = (long long)(consumer[k].second - producer[mid].second) * (consumer[k].first - producer[mid].first);
        if (res > ans) {
            ans = res;
            opt = k;
        }
    }

    maxVal = max<long long>(maxVal, ans);

    if (s <= mid - 1)
        work(s, mid - 1, p, opt);
    if (mid + 1 <= e)
        work(mid + 1, e, opt, q);
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    pTemp.reserve(n);
    cTemp.reserve(m);

    FOR(i, 0, n) {
        int price, day;
        cin >> price >> day;
        pTemp.push_back({price, day});
    }

    FOR(i, 0, m) {
        int price, day;
        cin >> price >> day;
        cTemp.push_back({price, day});
    }

    sort(pTemp.begin(), pTemp.end(), [](const pii& l, const pii& r) {
        return l.second != r.second
                       ? l.second < r.second
                       : l.first > r.first;
    });

    sort(cTemp.begin(), cTemp.end(), [](const pii& l, const pii& r) {
        return l.first != r.first
                       ? l.first > r.first
                       : l.second < r.second;
    });

    producer.push_back(pTemp[0]);
    FOR(i, 1, pTemp.size()) {
        if (pTemp[i].first <= producer.back().first) {
            producer.push_back(pTemp[i]);
        }
    }
    pTemp.clear();

    consumer.push_back(cTemp[0]);
    FOR(i, 1, cTemp.size()) {
        if (cTemp[i].second >= consumer.back().second) {
            consumer.push_back(cTemp[i]);
        }
    }
    cTemp.clear();

    n = producer.size();
    m = consumer.size();

    // todo: work
    work(0, n - 1, 0, m - 1);

    cout << maxVal << '\n';

    return 0;
}