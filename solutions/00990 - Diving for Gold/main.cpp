#include <bits/stdc++.h>

using namespace std;

int t, w;
int n;

int dp[30][1001];
bool taken[30][1001];

int depth[30];
int quantity[30];

int knapsack(int i, int time) {

    if (i == n) return 0;
    if (time == 0) return 0;

    if (taken[i][time]) return dp[i][time];

    if (time < depth[i] * 3 * w) {
        dp[i][time] = knapsack(i + 1, time);
    } else {
        dp[i][time] = max(knapsack(i + 1, time), knapsack(i + 1, time - 3 * w * depth[i]) + quantity[i]);
    }
    taken[i][time] = true;

    return dp[i][time];
}

int main() {
    int tt = 0;
    while (cin >> t >> w) {
        cin >> n;
        if (tt++) cout << endl;
        for (int i = 0; i < n; i++) {
            cin >> depth[i] >> quantity[i];
            for (int j = 0; j < 1001; j++) {
                taken[i][j] = false;
            }
        }

        int sum = knapsack(0, t);
        int sum2 = 0;
        int i = 0, time = t;

        cout << sum << endl;
        queue<int> ww, qq;

        while (sum2 != sum) {
            if (time - 3 * w * depth[i] < 0) {
                i++;
            } else {
                if (knapsack(i + 1, time) > knapsack(i + 1, time - 3 * w * depth[i]) + quantity[i]) {
                    i++;
                } else {
                    ww.push(depth[i]);
                    qq.push(quantity[i]);

                    sum2 += quantity[i];
                    time -= 3*w*depth[i];
                    i++;
                }
            }
        }
        cout << ww.size() << endl;
        while (ww.size()) {
            cout << ww.front() << " " << qq.front() << endl;
            ww.pop();
            qq.pop();
        }   
    }
}