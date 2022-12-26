#include <bits/stdc++.h>

using namespace std;

int n, m;
int numbers[100];

int main() {

    while (cin >> n >> m, n || m) {

        int a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d.%d", &a, &b);
            numbers[i] = a * 100 + b;
        }

        if (numbers[m - 1] > 5000) {
            cout << "100.00" << endl;
            continue;
        }

        int dp[10001] = {};
        int up = 10000 - numbers[m - 1];
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            if (i == m - 1) continue;

            for (int j = up - numbers[i]; j >= 0; j--) {
                if (dp[j]) {
                    dp[j + numbers[i]] = 1;
                }
            }
        }

        int ind = 0;
        while (dp[ind] == 0 || ind + numbers[m - 1] <= 5000) {
            ind++;
        }

        printf("%.2f\n", (double)numbers[m -1] / (ind + numbers[m - 1]) * 100);
    }
}