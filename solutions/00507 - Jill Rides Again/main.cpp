#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;
    for (int tc = 0; tc < test_cases; tc++) {
        int stops;
        int numbers[20000];
        cin >> stops;

        for (int i = 0; i < stops - 1; i++) cin >> numbers[i];

        int from = INT_MIN;
        int to = INT_MIN;
        int sum = 0;
        int max = 0;
        int from_max = INT_MIN;
        int to_max = INT_MIN;

        for (int i = 0; i < stops - 1; i++) {
            sum += numbers[i];

            if (sum < 0) {
                sum = 0;
                from = INT_MIN;
                to = INT_MIN;
                continue;
            }

            if (from == INT_MIN) from = i + 1;
            to = i + 2;

            if (sum > max || ( sum == max && (to - from > to_max - from_max || to_max == INT_MIN))) {
                max = sum;
                from_max = from;
                to_max = to;
            }
        }

        if (from_max == INT_MIN) {
            cout << "Route " << tc + 1 << " has no nice parts" << endl;
        } else {
            cout << "The nicest part of route " << tc + 1 << " is between stops " << from_max << " and " << to_max << endl;
        }
    }
}