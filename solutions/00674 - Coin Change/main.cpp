#include <bits/stdc++.h>

using namespace std;

int coin[] = {50, 25, 10, 5, 1};
long long dp[10000][5];
bool taken[10000][5];

long long cc (int rem, int index) {
    if (rem == 0) return 1;
    if (rem < 0) return 0;
    if (index == 5) return 0;

    if (taken[rem][index]) return dp[rem][index];
    taken[rem][index] = true;

    dp[rem][index] = cc(rem - coin[index], index) + cc(rem, index + 1);

    return dp[rem][index];
}

int main() {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 5; j++) {
            taken[i][j] = false;
        }
    }
    
    int n;
    while (cin >> n) {

        cout << cc(n, 0) << endl;
    }
}