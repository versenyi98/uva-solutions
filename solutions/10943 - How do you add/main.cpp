#include <bits/stdc++.h>

using namespace std;
                        //num  n
unsigned long long int dp[101][101];

int n, k;

void dynamic() {

    for (int i = 0; i < 101; i++) {
        dp[i][0] = 0;
    }
    for (int j = 1; j < 101; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
        }
    }
}

int main() {
    dynamic();
    while (cin >> n >> k, n || k) {
        cout << dp[n][k] << endl;
    }
}