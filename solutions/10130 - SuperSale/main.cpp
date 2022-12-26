#include <bits/stdc++.h>

using namespace std;

int value[1000];
int weight[1000];

bool taken[1000][400];
int dp[1000][400];

int family_member[100];

int products;
int family_size;

int knapsack(int i, int curr_w) {
    if (curr_w < 0) return 0;
    if (taken[i][curr_w]) return dp[i][curr_w];
    taken[i][curr_w] = true;

    if (curr_w == 0) {
        dp[i][curr_w] = 0;
    } else if (i == products) {
        dp[i][curr_w] = 0;
    } else if (weight[i] > curr_w) {
        dp[i][curr_w] = knapsack(i + 1, curr_w);
    }  else {
        dp[i][curr_w] = max(knapsack(i + 1, curr_w), knapsack(i + 1, curr_w - weight[i]) + value[i]);
    }

    return dp[i][curr_w];

}

int main() {

    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {
        cin >> products;
        for (int i = 0; i < products; i++) {
            cin >> value[i] >> weight[i];    
        }

        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 400; j++) {
                taken[i][j] = false;
                dp[i][j] = 0;
            }
        }

        cin >> family_size;
        for (int i = 0; i < family_size; i++) {
            cin >> family_member[i];
        }

        int sum = 0;
        for (int i = 0; i < family_size; i++) {
            sum += knapsack(0, family_member[i]);
        }

        cout << sum << endl;
    } 






} 