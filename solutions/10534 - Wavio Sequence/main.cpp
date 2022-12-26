#include <bits/stdc++.h>

int LIS[10001];
int LDS[10001];
int numbers[100001];
int lis[10001];
int lds[10001];

int LIS_size;
int LDS_size;

using namespace std;

void f_lis(int i) {

    int j = 0;
    while (numbers[i] > LIS[j] && j < LIS_size) j++;
    if (j == LIS_size) {
        LIS[LIS_size] = numbers[i];
        LIS_size++;
    } else if (numbers[i] < LIS[j]) {
        LIS[j] = numbers[i];
    }

    lis[i] = j;
}

void f_lds(int i) {

    int j = 0;
    while (numbers[i] > LDS[j] && j < LDS_size) j++;
    if (j == LDS_size) {
        LDS[LDS_size] = numbers[i];
        LDS_size++;
    } else if (numbers[i] < LDS[j]) {
        LDS[j] = numbers[i];
    }

    lds[i] = j;
}

int main() {

    int n;
    
    while (scanf("%d", &n) == 1) {
        LIS_size = 0;
        LDS_size = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            f_lis(i);
            f_lds(j);
        }

        int mm = 0;
        for (int i = 0; i < n; i++) mm = max(mm, min(lis[i], lds[i]));
        cout << mm * 2 + 1 << endl;
    }
}