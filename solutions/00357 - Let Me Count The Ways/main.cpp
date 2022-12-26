#include <bits/stdc++.h>

using namespace std;

int money[] = {1, 5, 10, 25, 50};
long long dp[30001][5];
bool taken[30001][5];

long long cc(int rem, int ind) {
    if (ind == 5) return 0;
    if (rem == 0) return 1;
    if (rem < 0) return 0;

    if (taken[rem][ind]) return dp[rem][ind];
    taken[rem][ind] = true;

    dp[rem][ind] = cc(rem, ind + 1) + cc(rem - money[ind], ind);
    return dp[rem][ind];
}

int main() {

    for (int i = 0; i <= 30000; i++) {
        for (int j = 0; j < 5; j++) {
            taken[i][j] = false;
        }
    }

    int n;
    while (cin >> n) {
        long long res = cc(n, 0);

        if (res == 1) {
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        } else {
            cout << "There are " << res << " ways to produce " << n << " cents change." << endl;
        }
    }
}