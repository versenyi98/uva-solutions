#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        int A[100][100];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }

        int meximum = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        int mex = A[k][l];

                        if (i > 0) mex -= A[i - 1][l];
                        if (j > 0) mex -= A[k][j - 1];
                        if (i > 0 && j > 0) mex += A[i - 1][j - 1];

                        meximum = max(mex, meximum);
                    }
                }
            }
        }
        cout << meximum << endl;
    }
}