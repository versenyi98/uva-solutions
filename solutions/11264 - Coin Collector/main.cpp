#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;
        long t[n];
        for (int j = 0; j < n; j++) {
            cin >> t[j];
        }

        long current_sum = 0;
        int current_count = 0;

        for (int j = 0; j < n - 1; j++) {
            if (current_sum + t[j] < t[j + 1]) {
                current_sum += t[j];
                current_count++;
            }
        }
        if (n > 1) current_count++;

        cout << current_count << endl;
    }


}