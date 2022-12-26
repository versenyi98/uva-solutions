#include <bits/stdc++.h>

using namespace std;

unsigned long long dp[30001][11];
bool taken[30001][11];

int money[]  = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

unsigned long long cc (int rem, int ind) {
    if (ind == 11) return 0;
    if (rem == 0) return 1;
    if (rem < 0) return 0;

    if (taken[rem][ind]) return dp[rem][ind];
    taken[rem][ind] = true;

    dp[rem][ind] = cc(rem, ind + 1) + cc(rem - money[ind], ind);
    return dp[rem][ind];
}

int main() {
    int t1, t2;
    int goal;

    while (scanf("%d.%d", &t1, &t2), goal = t1 * 100 + t2, goal) {
        printf("%3d.%.2d%17llu\n", t1, t2, cc(goal, 0));
    }
}