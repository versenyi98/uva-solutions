#include <bits/stdc++.h>
//#define endl "\n"

#define INF 1e9

using namespace std;

vector<int> price;
vector<int> favour;

int N; // number of friends
int x; // everyone pays at most x$
int T; // tea charge
int K; // number of dim sums
int total_money;

int dp[105][25][1200];

int solve(int k, int n, int money, int depth = 0) {
    if (n > 2 * (N + 1) || money > total_money) return -INF;
    if (dp[k][n][money] != -1) return dp[k][n][money];
    if (k == K || n == 2 * (N + 1)) return 0;

    int s1 = solve(k + 1, n + 1, money + price[k]) + favour[k];
    int s2 = solve(k + 1, n, money);
    int s3 = solve(k + 1, n + 2, money + 2 * price[k]) + 2 * favour[k];

    dp[k][n][money] = max(max(s1, s2), s3);

    return dp[k][n][money];

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> N >> x >> T >> K, N || x || T || K) {
        total_money = floor(double(x * (N + 1)) / 1.1 + 1e-6);

        price.clear();
        favour.clear();

        for (int j = 0; j < K; j++) {
            int p;
            cin >> p;
            price.push_back(p);

            int sum = 0;
            for (int i = 0; i <= N; i++) {
                int s;
                cin >> s;
                sum += s;
            }
            favour.push_back(sum);
        }
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 25; j++) {
                for (int k = 0; k < 1200; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        printf("%.2f\n", solve(0, 0, (N + 1) * T) / (double) (N + 1));
    }

    return 0;
}