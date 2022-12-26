#include <bits/stdc++.h>

using namespace std;

long long dp[10001][22];
bool taken[10001][22];

long long cc (long long rem, int i) {

    if (rem < 0) return 0;
    if (rem == 0) return 1;
    if (i == 22) return 0;
    if (taken[rem][i]) return dp[rem][i];
    taken[rem][i] = true;

    dp[rem][i] += cc(rem - (i * i * i), i) + cc(rem, i + 1);

    return dp[rem][i];
}

int main() {
    int n;

    while (cin >> n) {
        for (int i = 0; i < 10001; i++) {
            for (int j = 0; j < 22; j++) {
                dp[i][j] = 0;
                taken[i][j] = false;
            }
        }
        cout << cc(n, 1) << endl;
    }
}