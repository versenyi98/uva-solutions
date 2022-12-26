#include <bits/stdc++.h>

using namespace std;

int pyramid[9][9];

void calc(int i, int j) {
    if (i == 8) return;
    pyramid[i + 2][j + 1] = (pyramid[i][j] - (pyramid[i + 2][j] + pyramid[i + 2][j + 2])) / 2;
    pyramid[i + 1][j] = pyramid[i + 2][j] + pyramid[i + 2][j + 1];
    pyramid[i + 1][j + 1] = pyramid[i + 2][j + 2] + pyramid[i + 2][j + 1];
}

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        for (int i = 0; i < 9; i+= 2) {
            for (int j = 0; j <= i; j+= 2) {
                cin >> pyramid[i][j];
            }
        }

        for (int i = 0; i < 9; i+= 2) {
            for (int j = 0; j <= i; j+= 2) {
                calc(i, j);
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j <= i; j++) {
                if (j) cout << ' ';
                cout << pyramid[i][j];
            }
            cout << endl;
        }
    }
}