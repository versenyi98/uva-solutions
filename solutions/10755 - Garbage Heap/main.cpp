#include <bits/stdc++.h>

using namespace std;

int main() {

    int tt;
    cin >> tt;

    for (int ttt = 0; ttt < tt; ttt++) {
        if (ttt) cout << endl;
        int a, b, c;
        cin >> a >> b >> c;

        long long A[20][20][20];

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> A[i][j][k];

                    if (i > 0) A[i][j][k] += A[i - 1][j][k];
                    if (j > 0) A[i][j][k] += A[i][j - 1][k];
                    if (k > 0) A[i][j][k] += A[i][j][k - 1];

                    if (i > 0 && j > 0) A[i][j][k] -= A[i - 1][j - 1][k];
                    if (i > 0 && k > 0) A[i][j][k] -= A[i - 1][j][k - 1];
                    if (j > 0 && k > 0) A[i][j][k] -= A[i][j - 1][k - 1];

                    if (i > 0 && j > 0 && k > 0) A[i][j][k] += A[i - 1][j - 1][k - 1];
                }
            }
        }

        long long maxx = LONG_LONG_MIN;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                for (int k = 0; k < c; k++) {
                    for (int l = i; l < a; l++) {
                        for (int m = j; m < b; m++) {
                            for (int n = k; n < c; n++) {
                                long long maxxx = A[l][m][n];

                                if (i > 0) maxxx -= A[i - 1][m][n];
                                if (j > 0) maxxx -= A[l][j - 1][n];
                                if (k > 0) maxxx -= A[l][m][ k - 1];

                                if (i > 0 && j > 0) maxxx += A[i - 1][j - 1][n];
                                if (i > 0 && k > 0) maxxx += A[i - 1][m][k - 1];
                                if (j > 0 && k > 0) maxxx += A[l][j - 1][k - 1];

                                if (i > 0 && j > 0 && k > 0) maxxx -= A[i - 1][j - 1][k - 1];

                                maxx = max(maxx, maxxx);
                            }
                        }
                    }
                }
            }
        }

        cout << maxx << endl;
    }
}