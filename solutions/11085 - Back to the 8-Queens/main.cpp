#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

int t[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int valid[92][8];

int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}

bool validQueen() {

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (abs(i - j) == abs(t[i] - t[j])) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    int n = sizeof(t)/sizeof(t[0]);
    int counter = 0;

    for (int i = 0; i < fact(8); i++) {
	cout << i << endl;
        if (validQueen()) {
            for (int j = 0; j < 8; j++) {
            	valid[counter][j] = t[j];
            }
            counter++;
        }

        next_permutation(t, t+n);
    }

    int test[8];
    int case_ = 0;

    while (scanf("%d", &test[0]) == 1) {
        case_++;
        for (int i = 0; i < 7; i++) {
            scanf("%d", &test[i + 1]);
        }

        for (int i = 0; i < 8; i++) {
            test[i]--;
        }

        int minimum_distance = 64;
        
        for (int i = 0; i < 92; i++) {

            int current_distance = 0;

            for (int j = 0; j < 8; j++) {
                current_distance += (test[j]-valid[i][j] == 0 ? 0 : 1);
            }
            minimum_distance = min(current_distance, minimum_distance);
        }
        
        printf("Case %d: %d\n", case_, minimum_distance);
    }

    return 0;
}
