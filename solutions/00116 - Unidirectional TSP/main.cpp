#include <bits/stdc++.h>

using namespace std;

int A[10][100];
int dp[10][100];
int n, m;

int main() {

    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> A[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = A[i][m - 1];
        }
        
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = A[i][j] + min(dp[(i - 1 + 10 * n) % n][j + 1], min(dp[(i + 1) % n][j + 1], dp[i][j + 1]));
            }
        }

        int mx = INT_MAX, mx_pos = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i][0] < mx) {
                mx = dp[i][0];
                mx_pos = i;
            }
        }

        cout << mx_pos + 1;
        for (int i = 1; i < m; i++) {
            int new_mx = INT_MAX;
            if (dp[(mx_pos - 1 + n * 10) % n][i] <= dp[mx_pos][i] && dp[(mx_pos - 1 + n * 10) % n][i] <= dp[(mx_pos + 1) % n][i]) {
                new_mx = (mx_pos - 1 + n * 10) % n;
            } 
            
            if (dp[mx_pos][i] <= dp[(mx_pos - 1 + n * 10) % n][i] && dp[mx_pos][i] <= dp[(mx_pos + 1) % n][i]) {
                new_mx = min(new_mx, mx_pos);
            }
            
            if (dp[(mx_pos + 1) % n][i] <= dp[(mx_pos - 1 + n * 10) % n][i] && dp[mx_pos][i] >= dp[(mx_pos + 1) % n][i]) {
                new_mx = min(new_mx, (mx_pos + 1) % n);
            }

            cout << " ";
            cout << new_mx + 1;
            mx_pos = new_mx;
        }
        cout << endl;
        cout << mx << endl;
    }
}