#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    int ttt = 0;
    while (cin >> n >> m) {
        if (ttt) cout << endl;
        ttt++;
        int A[1000][1000];
        int res[1000][1000];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }

        for (int i = m - 1; i < n; i++) {
            for (int j = m - 1; j < n; j++) {
                res[i - m + 1][j - m + 1] = A[i][j];
                if (i != m - 1) res[i - m + 1][j - m + 1] -= A[i - m][j];
                if (j != m - 1) res[i - m + 1][j - m + 1] -= A[i][j - m];
                if (i != m - 1 && j != m - 1) res[i - m + 1][j - m + 1] += A[i - m][j - m];
            }
        }
        int result = 0;
        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < n - m + 1; j++) {
                cout << res[i][j] << endl;
                result += res[i][j];
            }
        }
        cout << result << endl;
    }
}