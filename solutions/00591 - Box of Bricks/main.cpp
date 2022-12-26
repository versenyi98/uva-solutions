#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int tc = 0;

    while (cin >> n, n) {

        int num[n];
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> num[i];
            sum += num[i];
        }

        int avg = sum / n;

        int ct = 0;

        for (int i = 0; i < n; i++) {
            ct += max(0, num[i] - avg);
        }

        cout << "Set #" << ++tc << "\nThe minimum number of moves is " << ct << ".\n\n";
    }
}