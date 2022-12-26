#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int num[20000];
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) cin >> num[i];
        int sum = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += num[i];

            if (sum <= 0) {
                sum = 0;
                continue;
            }
            maxi = max(maxi, sum);
        }

        if (maxi < 0) {
            cout << "Losing streak.\n";
        } else {
            cout << "The maximum winning streak is " << maxi << "." << endl;
        }
    }
}