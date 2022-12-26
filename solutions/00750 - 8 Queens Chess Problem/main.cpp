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

        if (validQueen()) {
            for (int j = 0; j < 8; j++) {
               valid[counter][j] = t[j];
            }
            counter++;
        }

        next_permutation(t, t+n);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        r--;
        c--;

        if (i) {
            printf("\n");
        }
        int sol_n = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        for (int j = 0; j < 92; j++) {
            if (valid[j][c] == r) {
                sol_n++;
                if (sol_n <= 9) {
                    printf(" ");
                }
                printf("%d     ", sol_n);
                for (int k = 0; k < 8; k++) {
                    printf(" %d", valid[j][k] + 1);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
