#include <bits/stdc++.h>

using namespace std;

int main() {

    int rows, cols;
    while (cin >> rows >> cols, rows || cols) {
        int A[100][100];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> A[i][j];
                if (A[i][j] == 1) {
                    A[i][j] = -20000;
                } else {
                    A[i][j] = 1;
                }
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }

        int maximum = INT_MIN;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = i; k < rows; k++) {
                    for (int l = j; l < cols; l++) {
                        int val = A[k][l];

                        if (i > 0) val -= A[i - 1][l];
                        if (j > 0) val -= A[k][j - 1];
                        if (j > 0 && i > 0) val += A[i - 1][j - 1];
                        maximum = max(maximum, val);
                    }
                }
            }
        }

        cout << max(maximum, 0) << endl;
    }
}