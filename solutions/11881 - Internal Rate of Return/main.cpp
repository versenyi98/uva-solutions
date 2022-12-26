#include <bits/stdc++.h>

using namespace std;

double eps = 10e-12;

int main() {

    int t;
    while (scanf("%d", &t), t) {

        int tt[t + 1];
        for (int i = 0; i < t + 1; i++) {
            scanf("%d", &tt[i]);
        }

        int cc = 0;
        double ans;
        double store;
        double l = -1 + eps;
        double r = 1000;

        int it = 100;

        while (it--) {
            double m = (l + r) / 2;
            double val = tt[0];

            for (int i = 0; i < t; i++) {
                val += ((double)tt[i + 1]/pow(1 + m, i + 1));
            }

            if (cc == 1 && fabs(val) < eps && fabs(val - store) > 10e-5) {
                cc++;
                break;
            }

            if (fabs(val) < eps && cc == 0) {
                ans = m;
                store = val;
                cc++;
            }

            if (val < 0) {
                r = m;
            }

            if (val > 0) {
                l = m;;
            }
        }

        if (cc == 0) {
            printf("No\n");
        } else if (cc == 1) {
            printf("%.2f\n", ans);
        } else {
            printf("Too many\n");
        }
    }
}