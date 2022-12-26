#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while (cin >> n, n) {
        bool wrong_row = false;
        bool wrong_col = false;
        int wrong_row_i;
        int wrong_col_i;

        int sum_h[n];
        int sum_v[n];

        for (int i = 0; i < n; i++) {
            sum_h[i] = 0;
            sum_v[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp;
                cin >> temp;
                if (temp) {

                    sum_h[i]++;
                    sum_v[j]++;

                }     
            }
        }

        for (int i = 0; i < n; i++) {
            if (sum_h[i] % 2 != 0) {
                if (!wrong_row) {
                    wrong_row = true;
                    wrong_row_i = i;
                } else {
                    wrong_col = true;
                    wrong_row = false;
                    break;
                }
            }

            if (sum_v[i] % 2 != 0) {
                if (!wrong_col) {
                    wrong_col = true;
                    wrong_col_i = i;
                } else {
                    wrong_col = true;
                    wrong_row = false;
                    break;
                }
            }
        }

        if (!wrong_row && !wrong_col) {
            cout << "OK" << endl;
        } else if (wrong_row && wrong_col) {
            cout << "Change bit (" << wrong_row_i + 1 << "," << wrong_col_i + 1 << ")" << endl;
        } else {
            cout << "Corrupt" << endl;
        }
    }
}