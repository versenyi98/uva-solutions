#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    while (cin >> n, n) {

        int x, y;
        int l[20000];
        int r[20000];

        memset(l, 0, 20000 * sizeof(int));
        memset(r, 0, 20000 * sizeof(int));

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            l[x - y + 500]++;
            r[x + y + 500]++;
        }
        int val = 0;
        int sum = 0;

        for (int i = 0; i < 20000; i++) {
            sum += l[i];
            val = max(val, sum);
            sum -= r[i];
        }
        cout << val << endl;
    }
}