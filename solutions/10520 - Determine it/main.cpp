#include <bits/stdc++.h>

using namespace std;

int64_t a[30][30];
int n;

int64_t dynamic(int i, int j) {

    if (i == n && j == 0) return 0;
    if (a[i][j] != -1) {
       return a[i][j]; 
    }

    if (i < j) {
        for (int k = i; k < j; k++) {
            a[i][j] = max(a[i][j], dynamic(i, k) + dynamic(k + 1, j));
        }
    } else {
        int64_t i_comp = 0, j_comp = 0;

        if (i < n) {
            for (int k = i + 1; k <= n; k++) {
                i_comp = max(i_comp, dynamic(k, 1) + dynamic(k, j));
            }
        }

        if (j != 0) {
            for (int k = 1; k < j; k++) {
                j_comp = max(j_comp, dynamic(i, k) + dynamic(n, k));
            }
        }

        a[i][j] = i_comp + j_comp;
    }

    return a[i][j];
}

int main() {
    int temp;
    while (cin >> n >> temp) {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                a[i][j] = -1;
            }
        }
        a[n][1] = temp;
        cout << dynamic(1, n) << endl;
    }
}