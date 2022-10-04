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
    vector<int> a(n, 0);
    vector<int> inc(n, 0);
    vector<int> dec(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    // get inc
    int cntm1 = 0;
    int recent = 1e9 + 5;
    int x = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == -1)
        {
            cntm1++;
        }
        else
        {
            if (a[i] > recent)
            {
                x = cntm1;
            }
            cntm1 = 0;
            recent = a[i];
        }
        inc[i] = ++x;
    }
    x = 0;
    cntm1 = 0;
    recent = 0;
    // get dec
    for (int i = n - 1; i >= 0; --i)
    {
        if (a[i] == -1)
        {
            cntm1++;
        }
        else
        {
            if (a[i] < recent)
            {
                x = cntm1;
            }
            cntm1 = 0;
            recent = a[i];
        }
        dec[i] = ++x;
    }

    bool pos = false;

    for (int i = 3; i <= n; ++i) {
        bool bb = true;
        for (int j = 0; j < n; j += i) {
            int s = j, e = min(n - 1, j + i - 1);
            if (e - s + 1 < 3) {
                bb = false;
                break;
            }

            auto isMountain = [&](int s, int e) {
                int ii = s + inc[s] - 1;
                if (ii == s) return false;
                if (ii >= e) {
                    if (a[e] == a[e - 1] || a[e] == -1 || a[e - 1] == -1) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (ii + dec[ii] - 1 >= e) {
                        return true;
                    } else {
                        return false;
                    }
                }
            };

            if (!isMountain(s, e)) {
                bb = false;
                break;
            }
        }
        if (bb) {
            pos = true;
            break;
        }
    }

    if (pos)
        cout << "Y\n";
    else
        cout << "N\n";
}