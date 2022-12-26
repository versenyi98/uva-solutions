#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int a = 2; a <= 200; a++) {
        for (int b = 2; b <= a; b++) {
            for (int c = b; c <= a; c++) {
                for (int d = c; d <= a; d++) {
                    int aa = a * a * a;
                    int bb = b * b * b;
                    int cc = c * c * c;
                    int dd = d * d * d;
                    if (aa == bb + cc + dd) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }


    return 0;
}