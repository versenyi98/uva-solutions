#include <bits/stdc++.h>

using namespace std;

int n;
int sum;
int num[100];
bool taken[100][50001];
int dp[100][50001];

int knapsack(int i, int rem_sum) {
    if (i == n) return abs(rem_sum - (sum - rem_sum));

    if (taken[i][rem_sum]) return dp[i][rem_sum];

    taken[i][rem_sum] = true;
    dp[i][rem_sum] = min(knapsack(i + 1, rem_sum - num[i]), knapsack(i + 1, rem_sum));

    return dp[i][rem_sum];
}

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        cin >> n;
        sum = 0;

        for (int j = 0; j < n; j++) {
            cin >> num[j];
            sum += num[j];
        }

        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= sum; k++) {
                taken[j][k] = false;
                dp[j][k] = 0;
            }
        }
        cout << knapsack(0, sum) << endl;
    }
}