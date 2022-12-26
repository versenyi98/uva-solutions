#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, d, r;
    while (scanf("%d %d %d", &n, &d, &r), n || d || r) {
        int morning[n];
        int evening[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &morning[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &evening[i]);
        }

        sort(morning, morning + n);
        sort(evening, evening + n, [] (int a, int b) { return a > b; });
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(0, morning[i] + evening[i] - d) * r;
        }
        printf("%d\n", res);
    }
}