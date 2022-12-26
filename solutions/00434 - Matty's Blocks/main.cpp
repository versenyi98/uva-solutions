#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {

        int size_of_table;
        cin >> size_of_table;

        int front[size_of_table], side[size_of_table];

        for (int i = 0; i < size_of_table; i++) cin >> front[i];
        for (int i = 0; i < size_of_table; i++) cin >> side[i];
        
        int maximal= 0, minimal = 0;
    
        sort(front, front + size_of_table);
        sort(side, side + size_of_table);

        int i = 0, j = 0;

        while (i < size_of_table && j < size_of_table) {
            if (front[i] < side[j]) {
                minimal += front[i];
                i++;
            } else if (front[i] == side[j]) {
                minimal += front[i];
                i++;
                j++;
            } else {
                minimal += side[j];
                j++;
            }
        }

        for (; j < size_of_table; j++) minimal += side[j];
        for (; i < size_of_table; i++) minimal += front[i];        

        for (int i = 0; i < size_of_table; i++) {
            for (int j = 0; j < size_of_table; j++) {
                maximal += min(front[i], side[j]);
            }
        }

        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", minimal, maximal - minimal);
    }
}