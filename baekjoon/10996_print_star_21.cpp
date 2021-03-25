#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (j % 2)
				cout << "*";
			else
				cout << " ";
		cout << "\n";
		for (int j = 1; j <= n; ++j)
			if (j % 2)
				cout << " ";
			else
				cout << "*";
		cout << "\n";
	}
    return 0;
}