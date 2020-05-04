#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

vector<bool> used(3333 + 1, false);
vector<int> ans;
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int offset[4] = {0, 2, 3, 1};

    int tc; cin >> tc;
    while (tc--) {
        long long n; cin >> n;
        if (n <= 4) {
            cout << n << "\n";
            continue;
        }
        long long x = n;
        long long i = 1;
        long long first, second, third;
        while (true) {
            if (x - i*3 > 0) {
                x -= i*3;
                i *= 4;
            } else {
                long long nthTriple = (x-1)/3;
                // cout << x << " "  << i << " " << nthTriple << endl;
                first = i + nthTriple;
                /*  
                    00 -> 00
                    10 -> 11
                    01 -> 10
                    11 -> 01
                */
                second = 0;
                for (int j = 0; j < 30; ++j) {
                    int bitPair = ((first >> (j*2)) & 3LL);
                    // cout << bitPair << " ";
                    switch (bitPair) {
                    case 0 :
                        second |= (0LL << (j*2));
                        break;
                    case 1 :
                        second |= (2LL << (j*2));
                        break;
                    case 2 :
                        second |= (3LL << (j*2));
                        break;
                    case 3 :
                        second |= (1LL << (j*2));
                        break;
                    default: ;
                    }
                }
                third = first ^ second;
                // cout << first << " " << second << " " << third << endl;
                break;
            }
        }
        int m = (n-1) % 3;
        cout << (m == 0 ? first : (m == 1 ? second : third)) << "\n";
    }
    
    return 0;
}