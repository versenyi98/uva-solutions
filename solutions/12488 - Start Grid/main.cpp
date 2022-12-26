#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        int start_grid[n];
        int end___grid[n];

        bool in_correct_place[n];

        for (int i = 0; i < n; i++) {
            cin >> start_grid[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> end___grid[i];
            in_correct_place[i] = false;
        }

        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            int current = end___grid[i];
            int counter = i;
            for (int j = n - 1; j >= 0; j--) {
                if (in_correct_place[start_grid[j] - 1]) continue;
                if (start_grid[j] == current) {
                    sum += i - counter;
                    in_correct_place[current - 1] = true;
                    break;
                }
                counter--;
            }
        }
        cout << sum << endl;
    }

    return 0;
}