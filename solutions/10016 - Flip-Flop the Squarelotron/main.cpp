#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {

        int n;

        while (cin >> n) {

            int t[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> t[i][j];
                }
            }

            for (int i = 0; i < (n + 1) / 2; i++) {

                int nn;
                cin >> nn;

                while (nn--) {
                    int rot;
                    cin >> rot;

                    if (rot == 1) {
                        for (int k = 0; k < n / 2; k++) {
                            for (int l = 0; l < n; l++) {
                                if (((k == i || k == n - 1 - i) && l <= n - 1 - i && l >= i) || ((l == i || l == n - 1 - i) && k >= i && k <= n - i - 1)) {
                                    swap(t[k][l], t[n - 1 - k][l]);
                                }
                            }
                        }
                        continue;
                    }

                    if (rot == 2) {
                        for (int k = 0; k < n; k++) {
                            for (int l = 0; l < n / 2; l++) {
                                if (((k == i || k == n - 1 - i) && l <= n - 1 - i && l >= i) || ((l == i || l == n - 1 - i) && k >= i && k <= n - i - 1)) {
                                    swap(t[k][l], t[k][n - 1 - l]);
                                }
                            }
                        }
                        continue;
                    }

                    if (rot == 3) {
                        for (int k = 0; k < n; k++) {
                            for (int l = k; l < n; l++) {
                                if (((k == i || k == n - 1 - i) && l <= n - 1 - i && l >= i) || ((l == i || l == n - 1 - i) && k >= i && k <= n - i - 1)) {
                                    swap(t[k][l], t[l][k]);
                                }
                            }
                        }
                        continue;
                    }

                    if (rot == 4) {
                        for (int k = 0; k < n - 1; k++) {
                            for (int l = 0; l < n - k; l++) {
                                if (((k == i || k == n - 1 - i) && l <= n - 1 - i && l >= i) || ((l == i || l == n - 1 - i) && k >= i && k <= n - i - 1)) {
                                    swap(t[k][l], t[n - 1 - l][n - 1 - k]);
                                }
                            }
                        }
                        continue;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j) cout << ' ';
                    cout << t[i][j];
                }
                cout << endl;
            }
        }
    }
}