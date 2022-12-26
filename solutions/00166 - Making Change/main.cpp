#include <bits/stdc++.h>

using namespace std;

int coins_[6];
int vals[6] = {5, 10, 20, 50, 100, 200};
int goal;

int change (int val) {

    int ret = 0;
    for (auto i : {200, 100, 50, 20, 10, 5}) {
        int tmp = val / i;
        val -= tmp * i;
        ret += tmp;
    }
    return ret;
}

int cc(int current, int coins[6], int dp=0) {
    if (current <= 0) return change(-current);

    int val = INT_MAX;

    for (int i = 0; i < 6; i++) {
        if (coins[i]) {
            int coin_copy[6];
            for (int j = 0; j < 6; j++) coin_copy[j] = coins[j];
            coin_copy[i]--;
            val = min(val, 1 + cc(current - vals[i], coin_copy, dp + 1));
        }
    }
    return val;
}

int main() {

    while (true) {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            cin >> coins_[i];
            sum += coins_[i];
        }

        if (!sum) break;

        double g;
        cin >> g;

        goal = g * 100;

        printf("%3d\n", cc(goal, coins_));
    }
}