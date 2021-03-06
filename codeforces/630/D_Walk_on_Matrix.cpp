#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    cout << "3 3\n";
    int A = (1<<18) - 1;
    int B = (1<<17) - 1;
    int C = (1<<17);
    cout << A << " " << B << " " << 0 << "\n";
    cout << C << " " << A << " " << n << "\n";
    cout << 0 << " " << 0 << " " << A << "\n";
    
    return 0;
}