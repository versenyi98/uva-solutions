#include <bits/stdc++.h>

using namespace std;

int n;
int m, S;
int dp[301][301];
int x[301], y[301];
bool taken[301][301];

int cc(int cx, int cy) {
    if (S * S < cx * cx + cy * cy) return 1000000000;
    if (S * S == cx * cx + cy * cy) return 0;
    
    if (taken[cx][cy]) return dp[cx][cy];
    taken[cx][cy] = true;

    for (int i = 0; i < m; i++) {
        dp[cx][cy] = min(dp[cx][cy], 1 + cc(cx + x[i], cy + y[i]));
    }

    return dp[cx][cy];
}

int main() {

    cin >> n;

    for (int nn = 0; nn < n; nn++) {
        cin >> m >> S;

        for (int i = 0; i <= 300; i++) {
            for (int j = 0; j <= 300; j++) {
                dp[i][j] = INT_MAX;
                taken[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i];
        }

        int ret = cc(0, 0);

        if (ret >= 1000000000) {
            cout << "not possible" << endl;
        } else {
            cout << ret << endl;
        }
    }
}