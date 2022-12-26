#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int ttt = 0; ttt < tc; ttt++) {
        int n;
        cin >> n;

        long long A[250][250];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i + n][j] = A[i][j];
                A[i][j + n] = A[i][j];
                A[i + n][j + n] = A[i][j];
            }
        }

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        
        long long meximum = LONG_MIN;

        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                for (int k = i; k < min(2 * n, i + n); k++) {
                    for (int l = j; l < min(2 * n, j + n); l++) {
                        long long mex = A[k][l];

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