#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= 2*n - 1; ++i) {
        int m = (i <= n ? i : 2*n - i);
        for (int j = 1; j <= m; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}