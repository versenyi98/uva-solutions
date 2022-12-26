#include <bits/stdc++.h>

using namespace std;

int n;
int goal;
int money[100];
pair<int, int> dp[10001][100];
bool taken[10001][100];
pair<int, int> cc (int current, int index) {

    if (index == n && current < goal) return {INT_MAX, INT_MAX};
    if (current >= goal) return {current, 0};

    if (taken[current][index]) return dp[current][index];
    taken[current][index] = true;

    pair<int, int> ret1 = {INT_MAX, INT_MAX};
    pair<int, int> ret2 = {INT_MAX, INT_MAX};

    ret1 = cc(current, index + 1);
    ret2 = cc(current + money[index], index + 1);
    ret2.second += 1;

    if (ret1.first < goal) {
        dp[current][index] = ret2;
    } else if (ret1.first < ret2.first) {
        dp[current][index] = ret1;
    } else if (ret1.first > ret2.first) {
        dp[current][index] = ret2;
    } else if (ret1.second < ret2.second) {
        dp[current][index] = ret1;
    } else {
        dp[current][index] = ret2;
    }

    return dp[current][index];
}

int main() {

    int test_cases;

    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        cin >> goal;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> money[j];
        }
        
        for (int j = 0; j <= 10000; j++) {
            for (int k = 0; k < 100; k++) {
                taken[j][k] = false;
            }
        }

        auto solution = cc(0, 0);
        cout << solution.first << " " << solution.second << endl;
    }
}