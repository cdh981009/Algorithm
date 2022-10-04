#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr, aux;
    arr.resize(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    aux = arr;

    sum /= n;
    ll ans = INT64_MAX;

    auto op = [&]()
    {
        ll curr = 0;
        ll cost = 0;
        for (int i = 0; i < 3 * n; ++i)
        {
            int ind = i % n;
            if (aux[ind] > sum)
            {
                curr += aux[ind] - sum;
                aux[ind] = sum;
            }
            else if (aux[ind] < sum)
            {
                ll x = min(curr, sum - aux[ind]);
                curr -= x;
                aux[ind] += x;
            }
            cost += curr;
        }

        return cost;
    };

    ans = op();
    aux = arr;
    reverse(aux.begin(), aux.end());
    ans = min(ans, op());

    cout
        << ans << '\n';
}