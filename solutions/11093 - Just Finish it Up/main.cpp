#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    scanf("%d", &test_cases);

    for (int tt = 0; tt < test_cases; tt++) {

        int n;
        scanf("%d", &n);

        int provided[n], needed[n];
        int prov_sum = 0, need_sum = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &provided[i]);
            prov_sum += provided[i];
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &needed[i]);
            need_sum += needed[i];
        }

        if (need_sum > prov_sum) {
            printf("Case %d: Not possible\n", tt + 1);
            continue;
        }

        int sol = 0;
        int current_amount = 0;
        for (int i = 0; i < n; i++) {

            if (current_amount < 0) {
                sol = i;
                current_amount = 0;
            }

            current_amount += provided[i];
            current_amount -= needed[i];
        }
        printf("Case %d: Possible from station %d\n", tt + 1, sol + 1);
    }
}