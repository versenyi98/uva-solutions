#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        int table[100][100];
        int dp[100][100]; 
        int s_z;
        int maximum = INT_MIN;
        int fx, fy, tx, ty;
        int occupied;

        cin >> s_z;
        for (int i = 0; i < s_z; i++) {
            for (int j = 0; j < s_z; j++) {
                table[i][j] = 1;
            }
        }
        cin >> occupied;
        for (int i = 0; i < occupied; i++) {
            cin >> fy >> fx >> ty >> tx;    
            for (int j = fy - 1; j < ty; j++) {
                for (int k = fx - 1; k < tx; k++) {
                    table[j][k] = -100000;
                }
            }
        }

        for (int i = 0; i < s_z; i++) {
            for (int j = 0; j < s_z; j++) {
                dp[i][j] = table[i][j];
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
                if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
            }
        }

        for (int i = 0; i < s_z; i++) {
            for (int j = 0; j < s_z; j++) {   
                for (int k = i; k < s_z; k++) {
                    for (int l = j; l < s_z; l++) {
                        int val = dp[k][l];
                        if (i > 0) val -= dp[i - 1][l];
                        if (j > 0) val -= dp[k][j - 1];
                        if (i > 0 && j > 0) val += dp[i - 1][j - 1];
                        maximum = max(maximum, val);
                    }
                }
            }
        }
        cout << max(maximum, 0) << endl;
    }
}