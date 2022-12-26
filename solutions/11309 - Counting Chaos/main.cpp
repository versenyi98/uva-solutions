#include <bits/stdc++.h>

int A, B;

using namespace std;

bool ispalindromic(string str) {
    return str.length() == 0 || str.length() == 1 || (str[0] == str.back() && ispalindromic(str.substr(1, str.length() - 2)));
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%2d:%2d", &A, &B);

        B = B + 100 * A;
        B++;
        if (B % 100 == 60) {
            B = B / 100 * 100 + 100;
        }

        if (B / 100 == 24) {
            B %= 100;
        }
        while (!ispalindromic(std::to_string(B))) {
            B++;

            if (B % 100 == 60) {
                B = (B / 100 + 1) * 100;
            }

            if (B / 100 == 24) {
                B %= 100;
            }
        }
        printf("%.2d:%.2d\n", B / 100, B % 100);
    }
}