#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (uint64_t i = 1; i <= 2000; i++) {
        for (uint64_t j = i; j <= 2000 - i; j++) {
            for (uint64_t k = j; k <= 2000 - i - j; k++) {
                if (i * j * k == 1000000) continue;
                if ((1000000 * (i + j + k)) % (i * j * k - 1000000) != 0) continue;
                uint64_t l = 1000000 * (i + j + k) / (i * j * k - 1000000);
                if (k > l) continue;
                if (i + j + k + l > 2000) continue;

                if (i * j * k * l == 1000000 * (i + j + k + l)) {
                    printf("%.2f %.2f %.2f %.2f\n", i / 100.00, j / 100.00, k / 100.00, l / 100.00);
                }
            }
        }
    }

    return 0;
}