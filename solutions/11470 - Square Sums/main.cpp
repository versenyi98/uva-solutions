#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int test_cases = 0;

    while (cin >> n, n) {

        int size = (n + 1)/2;
        int ans[size];
        int table[n][n];

        for (int i = 0; i < size; i++) ans[i] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> table[i][j];
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = i; j < n - i; j++) {
                ans[i] += table[i][j];
            }
            for (int j = i + 1; j < n - i; j++) {
                ans[i] += table[j][i];
            }
            for (int j = i + 1; j < n - i; j++) {
                ans[i] += table[n - i - 1][j];
            }
            for (int j = i + 1; j < n - i - 1; j++) {
                ans[i] += table[j][n - i - 1];
            }
        }

        cout << "Case " << ++test_cases << ":";
        for (int i = 0; i < size; i++) {
            cout << ' ' << ans[i];
        }
        cout << endl;
        
    }
}