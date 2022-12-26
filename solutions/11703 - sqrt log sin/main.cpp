#include <bits/stdc++.h>

int dp[1000000];
bool taken[1000000];

int func(int index) {
    if (taken[index]) return dp[index];
    taken[index] = true;
    dp[index] = (func(index - sqrt(index)) + func(log(index)) + func(index * sin(index) * sin(index))) % 1000000;
    return dp[index];
}

int main() {
    for (int i = 1; i <= 1000000; i++) {
        taken[i] = false;
    }
    taken[0] = true;
    dp[0] = 1;

    int n;
    while (std::cin >> n, n != -1) std::cout << func(n) << std::endl;
}