#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {

    std::ios_base::sync_with_stdio(false);

    while (cin >> n >> m, n || m) {
        char big[n][n];
        char small[4][m][m];
        int occurance[4];
        for (int i = 0; i < 4; i++) occurance[i] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> big[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> small[0][i][j];
                small[1][j][m - 1 - i] = small[0][i][j];
                small[2][m - 1 - i][m - 1 - j] = small[0][i][j];
                small[3][m - 1 - j][i] = small[0][i][j];

            }
        }

        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                for (int k = 0; k < 4; k++) {
                    bool good = true;
                    for (int ii = 0; ii < m && good; ii++) {
                        for (int jj = 0; jj < m && good; jj++) {
                            good = (good && big[i + ii][j + jj] == small[k][ii][jj]);
                        }
                    }
                    if (good) {
                        occurance[k]++;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (i) cout << ' ';
            cout << occurance[i];
        }
        cout << endl;
    }
}