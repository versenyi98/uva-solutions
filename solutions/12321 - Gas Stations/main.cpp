#include <bits/stdc++.h>

using namespace std;

int main() {
    int len, gas_stations;
    while (scanf("%d", &len), scanf("%d", &gas_stations), len || gas_stations) {

        pair<int, int> left_right[gas_stations];

        for (int i = 0; i < gas_stations; i++) {
            int center, radius;
            scanf("%d", &center);
            scanf("%d", &radius);
            left_right[i].first = max(0, center - radius);
            left_right[i].second = min(len, center + radius);
        }

        int sizeof_array = sizeof(left_right) / sizeof(left_right[0]);

        sort(left_right, left_right + sizeof_array, [] (pair<int, int> a, pair<int, int> b) {
            return a.first < b.first || (a.first == b.first && a.second > b.first);
        });

        int left_bound = 0;
        int max_right = 0;
        int max_index = 0;
        int counter = 0;
        int current = 0;
        bool wrong = false;
        while (!wrong && left_bound != len) {
            max_right = 0;
            max_index = -1;
            while (current < gas_stations && left_right[current].first <= left_bound) {
                if (left_right[current].second > max_right) {
                    max_right = left_right[current].second;
                    max_index = current;
                }
                current++;
            }

            if (max_index == -1) {
                wrong = true;
            } else {
                counter++;
                left_bound = left_right[max_index].second;
            }
        }

        if (wrong) {
            printf("-1\n");
        } else {
            printf("%d\n", gas_stations - counter);
        }
    }
}