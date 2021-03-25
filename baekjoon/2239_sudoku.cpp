// 2239: sudoku
// https://www.acmicpc.net/problem/2239
#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR_(i, a, b) for (int i = (a); i <= (b); ++i)

int room[9];
int row[9];
int column[9];

int arr[9][9];

bool fill(int i) {
    if (i == 81) {
        FOR(y, 0, 9) {
            FOR(x, 0, 9) {
                printf("%d", arr[x][y]);
            }
            printf("\n");
        }

        return true;
    }

    int x = i % 9;
    int y = i / 9;

    if (arr[x][y]) {
        return fill(i + 1);
    } else {
        FOR_(n, 1, 9) {
            if ((room[(y / 3) * 3 + (x / 3)] & (1 << n)) ||
                    (row[y] & (1 << n)) ||
                    (column[x] & (1 << n))) {
                continue;
            }

            arr[x][y] = n;
            room[(y / 3) * 3 + (x / 3)] |= (1 << arr[x][y]);
            row[y] |= (1 << arr[x][y]);
            column[x] |= (1 << arr[x][y]);

            if (fill(i + 1))
                return true;

            room[(y / 3) * 3 + (x / 3)] ^= (1 << arr[x][y]);
            row[y] ^= (1 << arr[x][y]);
            column[x] ^= (1 << arr[x][y]);
            arr[x][y] = 0;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FOR(y, 0, 9) {
        FOR(x, 0, 9) {
            scanf(" %1d", &arr[x][y]);
            if (arr[x][y]) {
                room[(y / 3) * 3 + (x / 3)] |= (1 << arr[x][y]);
                row[y] |= (1 << arr[x][y]);
                column[x] |= (1 << arr[x][y]);
            }
        }
    }

    fill(0);

    return 0;
}