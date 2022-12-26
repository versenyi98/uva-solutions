#include <bits/stdc++.h>

int numbers[20000];
int LDS[20000];
int lds[20000];
int LDS_size;
int n;

using namespace std;

int lds_f(int i) {

    int j = 0;

    while (numbers[i] <= LDS[j] && j < LDS_size) j++;
    if (j == LDS_size) {
        LDS[LDS_size] = numbers[i];
        LDS_size++;
    } else {
        if (numbers[i] > LDS[j]) {
            LDS[j] = numbers[i];
        }
    }

    return j;
}

int main() {

    int number;
    int tc = 0;
    while (cin >> number, number != -1) {
        n = 0;
        LDS_size = 0;
        tc++;
        numbers[n++] = number;

        while (cin >> number, number != -1) {
            numbers[n++] = number;
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            lds[i] = lds_f(i);
            mx = max(mx, lds[i]);
        }
        if (tc != 1) cout << endl;
        cout << "Test #" << tc << ":" << endl;
        cout << "  maximum possible interceptions: ";
        cout << mx + 1 << endl;
    }
} 