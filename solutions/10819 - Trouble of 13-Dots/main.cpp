#include <bits/stdc++.h>

using namespace std;

int dp[20000];

int money, lines;
int origi_sum = 0;
int value[100], favour[100];

int main() {

    while (cin >> money >> lines) {

        for (int i = 0; i < lines; i++) {
            cin >> value[i] >> favour[i];
        }
        for (int i = 0; i < 20000; i++) dp[i] = 0;

        int money2 = money;
        if (money > 1800) money2 += 200;

        for (int i = 0; i < lines; i++) {
            for (int j = money2; j >= value[i]; j--) {
                if (dp[j - value[i]] > 0 || j == value[i]) {
                    dp[j] = max(dp[j], dp[j - value[i]] + favour[i]);    
                }
            }
        }
        int m = 0;
        if (money >= 1801 && money <= 2000) {
            for (int i = 0; i <= money; i++) {
                m = max(m , dp[i]);
            }
            for (int i = 2001; i <= money2; i++) {
                m = max(m, dp[i]);
            }
        } else {
            for (int i = 0; i <= money2; i++) {
                m = max(m , dp[i]);
            } 
        }

        cout << m << endl;
    }
}