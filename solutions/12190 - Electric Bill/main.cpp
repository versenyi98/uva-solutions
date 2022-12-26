#include <bits/stdc++.h>

using namespace std;

int cost[] = {2, 3, 5, 7};
int valu[] = {100, 9900, 1000000 - 10000, INT_MAX};

int both_energy(int price) {
    int both_en = 0;

    for (int i = 0; i < 4; i++) {
        if (price == 0) break;
        int diff = min(valu[i] * cost[i], price);
        both_en += (diff / cost[i]);
        price -= diff;
    }

    return both_en;
}

int money_for_energy(int energy) {
    int money = 0;

    for (int i = 0; i < 4; i++) {
        if (energy == 0) break;
        int diff = min(valu[i], energy);
        money += diff * cost[i];
        energy -= diff;
    }

    return money;
}

int main() {

    int both_price, diff_price;
    
    while (scanf("%d", &both_price), scanf("%d", &diff_price), both_price || diff_price) {
        int both_en = both_energy(both_price);
        int u = both_en;
        int l = 0;
        int me = 0, neighbour = 0, m = 0;
        int cc = 0;
        while (l < u) {
            m = (u + l) / 2;
            neighbour = money_for_energy(both_en - m);
            me = money_for_energy(m);
            
            if (neighbour - me == diff_price) {
                break;
            }

            if (neighbour - me > diff_price) {
                l = m;
            } else {
                u = m;
            }
        }

        printf("%d\n", me);
    }

}