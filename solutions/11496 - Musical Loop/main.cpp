#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while (cin >> n, n) {
        int t[n];
        for (int i = 0; i < n; i++) cin >> t[i];

        bool increase = t[1] > t[0];
        int counter = 0;

        for (int i = 0; i <= n; i++) {
            if (increase != t[(i + 1) % n] > t[i % n]) {
                increase = !increase;
                counter++;
            }
        }
        cout << counter << endl;
    }
}