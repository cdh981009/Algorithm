#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
    int tc; cin >> tc;
    while (tc--) {
        long long x; cin >> x;
        long long cnt = 0;
        while (x > 1) {
            long long h = (sqrt(x*24 + 1) - 1)/6;
			long long card = (3*h*h + h) / 2;
			// cout << card << endl;
            cnt += x / card;
            x %= card;
        }
        cout << cnt << "\n";
    }
    return 0;
}