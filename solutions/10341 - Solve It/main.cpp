#include <bits/stdc++.h>

using namespace std;

int main() {

    int p, q, r, s, t, u;
    double eps = 1e-10;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
        double l = 0, h = 1;
        double val, x;
        int cc = 75;

        while (cc--) {
            x = (l + h) / 2;
            val = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;

            if (fabs(val) < eps) break;
            if (val > 0) {
                l = x;
            } else {
                h = x;
            }
            if (cc == 0) {
                val = -1;
            }
        }
        
        if (val != -1) {
            printf("%.4f\n", x);
        } else {
            printf("No solution\n");
        }
    }
}