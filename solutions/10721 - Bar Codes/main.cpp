#include <bits/stdc++.h>

using namespace std;

int64_t dp[51][51][51];

int n, k, m;

int64_t dynamic(int nn, int kk, int mm) {

    if (nn == 0 && kk == 0) return 1;
    if (nn <= 0) return 0;
    if (kk <= 0) return 0;
    if (dp[nn][kk][mm] != -1) return dp[nn][kk][mm];

    int64_t val = 0;

    for (int i = 0; i < mm; i++) {
        val += dynamic(nn - i - 1, kk - 1, mm);
    }
    dp[nn][kk][mm] = val;
    return val;
}

int main() {

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            for (int k = 0; k < 51; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    while (cin >> n >> k >> m) {
        cout << dynamic(n, k, m) << endl;
    }
}