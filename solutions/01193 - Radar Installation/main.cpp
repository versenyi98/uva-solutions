#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    double d;
    int tt = 0;
    while (scanf("%d", &n), scanf("%lf", &d), n || d) {
        tt++;
        bool wrong_test = false;
        pair<double, double> island[n];
        for (int i = 0; i < n; i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);

            if (y > d) wrong_test = true;

            island[i].first = x - sqrt(d*d - y*y);
            island[i].second = x + sqrt(d*d - y*y);

        }
        sort(island, island+n);
        if (wrong_test) {
            printf("Case %d: -1\n", tt);
            continue;
        }

        double left_bound = -1e10;

        int i = 0;
        int ret = 0;
        while (i < n) {
            while (i < n && island[i].first <= left_bound) {
                left_bound = min(left_bound, island[i].second);
                i++;
            }
            ret++;
            left_bound = island[i].second;
        }
        printf("Case %d: %d\n", tt, ret - 1);

    }
}