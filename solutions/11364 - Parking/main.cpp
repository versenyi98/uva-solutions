#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;
        int t[n];
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        sort(t, t + n);

        int counter = 0;

        for (int i = 1; i < n; i++) {
            counter += (t[i] - t[i - 1]);
        }
        counter += t[n - 1] - t[0];
        cout << counter << endl;
    }
}