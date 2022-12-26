#include <bits/stdc++.h>

using namespace std;

int n;
int ferry;
int tests;
int cars[1001];
int dp[1001][10001];
bool taken[1001][10001];
bool left [1001];
int goal = 0;

int knapsack (int i, int remleft, int remright) {
    if (i == n) return 0;
    
    if (cars[i] > remleft && cars[i] > remright) {
        return 0;
    }

    if (taken[i][remleft]) return dp[i][remleft];
    if (cars[i] <= remleft && cars[i] > remright) {
        dp[i][remleft] = knapsack(i + 1, remleft - cars[i], remright) + cars[i];
    }

    if (cars[i] <= remright && cars[i] > remleft) {
        dp[i][remleft] = knapsack(i + 1, remleft, remright - cars[i]);
    }

    if (cars[i] <= remleft && cars[i] <= remright) {
        dp[i][remleft] = max(knapsack(i + 1, remleft - cars[i], remright) + cars[i],
                                knapsack(i + 1, remleft, remright - cars[i]));
    }

    taken[i][remleft] = true;
    goal = max(goal, i + 1);
    return dp[i][remleft];
}

void trace(int i, int remleft, int remright) {
    if (i == goal) return;
    if (remleft < cars[i] && remright < cars[i]) return;

    
    if (remleft < cars[i]) {
        cout << "starboard" << endl;
        trace(i + 1, remleft, remright - cars[i]);
        return;
    }

    if (remright < cars[i]) {
        cout << "port" << endl;
        trace(i + 1, remleft - cars[i], remright);
        return;
    }

    if (knapsack(i + 1, remleft, remright - cars[i]) > knapsack(i + 1, remleft - cars[i], remright) + cars[i]) {
        cout << "starboard" << endl;
        trace(i + 1, remleft, remright - cars[i]);
    } else {
        cout << "port" << endl;
        trace(i + 1, remleft - cars[i], remright);
    }
}
int main() {

    cin >> tests;

    for (int ti = 0; ti < tests; ti++) {
        n = 0;
        goal = 0;
        cin >> ferry;
        ferry *= 100;

        while (cin >> cars[n++], cars[n - 1]) {}
        n--;
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= 10000; j++) {
                taken[i][j] = false;
                dp[i][j] = 0;
            }
        }
        if (ti) cout << endl;
        knapsack(0, ferry, ferry);
        cout << goal << endl;
        trace(0, ferry, ferry);
    }   
}