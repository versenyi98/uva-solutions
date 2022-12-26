#include <bits/stdc++.h>

using namespace std;

int main() {

    int tt;
    cin >> tt;

    for (int tc = 0; tc < tt; tc++) {
        int n;
        char c, h;
        scanf("\n%c %c %d", &c, &h, &n);
        long long t[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> t[i][j];
            }
        }

        bool good = true;

        for (int i = 0; i < n && good; i++) {
            for (int j = 0; j < n && good; j++) {
                good = t[i][j] >= 0 && good && t[i][j] == t[n - 1 - i][n - 1 - j];
            }
        }

        cout << "Test #" << tc + 1 << ": " << (good ? "Symmetric." : "Non-symmetric.") << endl;
    }
}