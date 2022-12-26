#include <bits/stdc++.h>

using namespace std;

int dp[71][71][71];
bool t[71][71][71];

int N, T, P;

int F (int NN, int TT, int PP) {

    if (NN == 1) return 1;
    if (TT < NN * PP) return 0;

    if (t[NN][TT][PP]) return dp[NN][TT][PP];
    t[NN][TT][PP] = true;
    dp[NN][TT][PP] = 0;

    for (int i = 0; i <= TT - NN * PP; i++) {
        dp[NN][TT][PP] += F(NN - 1, TT - PP - i, PP);
    }

    return dp[NN][TT][PP];
}

int main() {

    for (int i = 0; i < 71; i++) {
        for (int j = 0; j < 71; j++) {
            for (int k = 0; k < 71; k++) {
                t[i][j][k] = false;
            }
        }
    }

    int n;
    cin >> n;

    while (n--) {
        cin >> N >> T >> P;
        cout << F(N, T, P) << endl;
    }
}