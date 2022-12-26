#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
int n, k;

int shortcut[188][1121][15];
bool taken[188][1121][15];

void generate_primes() {

    for (int i = 2; i <= 1120; i++) {
        bool b  = false;
        for (auto j : primes) if (i % j == 0) {
            b = true;
            break;
        }
        if (b) continue;
        primes.push_back(i);
    }
}

int knapsack(int i, int rem_count, int rem_sum) {

    if (rem_count < 0) return 0;
    if (rem_sum < 0) return 0;
    if (i > primes.size()) return 0;

    if (taken[i][rem_sum][rem_count]) {
        return shortcut[i][rem_sum][rem_count];
    } else if (rem_sum == 0 && rem_count == 0) {
        shortcut[i][rem_sum][rem_count] = 1;
    } else {
        shortcut[i][rem_sum][rem_count] = knapsack(i + 1, rem_count - 1, rem_sum - primes[i]) + knapsack(i + 1, rem_count, rem_sum);
    } 
    taken[i][rem_sum][rem_count] = true;

    return shortcut[i][rem_sum][rem_count];
}

int main() {

    generate_primes();
    //for (auto i : primes) cout << i << "\t";
    //cout << endl;
    for (int k = 0; k < 188; k++) {
        for (int i = 0; i < 1121; i++) {
            for (int j = 0; j < 15; j++) {
                taken[k][i][j] = false;
            }
        }
    }

    while (cin >> n >> k, n || k) {
        cout << knapsack(0, k, n) << endl;
    }


}