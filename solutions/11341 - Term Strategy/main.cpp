#include <bits/stdc++.h>

using namespace std;

int N, M;
int   tb[10][101];
double   dp[10][101][101];
bool  tk[10][101][101];

double knapsack(int course, int hours, int remaining) {

    if (remaining <= 0 && course != N) return -1000;
    if (course == N) return 0;

    if (remaining < hours) return -1000;

    if (tk[course][hours - 1][remaining]) return dp[course][hours - 1][remaining];
    tk[course][hours - 1][remaining] = true;

    if (tb[course][hours - 1] < 5) {
        dp[course][hours - 1][remaining] = knapsack(course, hours + 1, remaining);
    } else {
        dp[course][hours - 1][remaining] = max(knapsack(course + 1, 1, remaining - hours) + tb[course][hours - 1],
                                       knapsack(course, hours + 1, remaining));
    }

    return dp[course][hours - 1][remaining];
}

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> tb[i][j];
            }
        }

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 101; j++) 
                for (int k = 0; k < 101; k++)
                    tk[i][k][j] = false;

        if (knapsack(0, 1, M) < N * 5) {
            cout << "Peter, you shouldn't have played billiard that much." << endl;
        } else {
            printf("Maximal possible average mark - %.2f.\n", roundf(100 * knapsack(0, 1, M) / N) / 100);
        }
    }
}