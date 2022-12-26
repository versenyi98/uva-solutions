#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    scanf("%d", &tc);

    for (int tt = 0; tt < tc; tt++) {
        int m;
        scanf("%d", &m);
        int numbers[m + 1];
        numbers[0] = 0;

        for (int i = 1; i <= m; i++) {
            scanf("%d", &numbers[i]);
        }

        int l = 1;
        int r = 10000500 + m;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            int mid_cop = mid;
            bool mark = false;
            for (int i = 0; i < m; i++) {
                if (numbers[i + 1] - numbers[i] == mid_cop) {
                    mid_cop--;
                } else if (numbers[i + 1] - numbers[i] > mid_cop) {
                    mark = true;
                    break;
                }
            }

            if (mark) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        printf("Case %d: %d\n", tt + 1, ans);
    }



}