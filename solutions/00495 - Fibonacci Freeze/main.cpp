#include <bits/stdc++.h>

using namespace std;

int fib[5001][1046];

int main() {

    for (int i = 0; i <= 5000; i++) {
        for (int j = 0; j <= 1045; j++) {
            fib[i][j] = 0;
        }
    }

    fib[0][0] = 0;
    fib[1][0] = 1;

    for (int i = 2; i <= 5000; i++) {
        for (int j = 0; j < 1045; j++) {
            int sum = fib[i - 1][j] + fib[i - 2][j];
            fib[i][j] += sum;
            int old = fib[i][j];
            fib[i][j] = fib[i][j] % 10;

            fib[i][j + 1] = old / 10;
        }
    }

    int i;

    while (cin >> i) {
        cout << "The Fibonacci number for " << i << " is ";
        bool started = false;
        for (int j = 1045; j >= 0; j--) {
            if (!started) {
                if (fib[i][j] == 0) continue;
                started = true;
            }
            cout << fib[i][j];
        }
        if (!started) cout << 0;
        cout << endl;
    } 
}