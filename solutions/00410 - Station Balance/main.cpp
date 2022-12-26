#include <bits/stdc++.h>

using namespace std;

int main() {

    int C, S;
    int set_num = 0;
    while (scanf("%d %d", &C, &S) == 2) {
        int mass[2 * C];
        set_num++;

        for (int i = 0; i < S; i++) {
            scanf("%d", &mass[i]);
        }
        
        for (int i = S; i < 2 * C; i++) {
            mass[i] = 0;
        }

        sort(mass, mass + 2 * C);

        vector<int> centrifuge[C];
        int sum[C];
        double sum_of_all = 0;
        
        for (int i = 0; i < C; i++) {
            if (mass[i]) centrifuge[i].push_back(mass[i]);
            if (mass[2 * C - 1 - i]) centrifuge[i].push_back(mass[2 * C - 1 - i]);

            sum[i] = 0;
            sum[i] += mass[i];
            sum[i] += mass[2 * C - 1 - i];
            sum_of_all += sum[i];
        }
        
        double avg = sum_of_all / (double) C;
        double diff = 0;
        printf("Set #%d\n", set_num);
        for (int i = 0; i < C; i++) {
            printf("%2d:", i);
            for (auto j : centrifuge[i]) printf(" %d", j);
            printf("\n");
            diff += abs(avg - sum[i]);
        }
        printf("IMBALANCE = %.5f\n\n", diff);        
    }
}