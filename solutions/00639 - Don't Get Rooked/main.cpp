#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

uint64_t pow(uint64_t n, uint64_t k) {
    return k == 0 ? 1 : n * pow(n, k - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    uint64_t dim;

    while (cin >> dim, dim) {
        string table[dim];
        string cpy[dim];

        for (uint64_t i = 0; i < dim; i++) {
            cin >> table[i];
            cpy[i] = table[i];
        }

        uint64_t bound = pow(2, dim * dim);
        uint64_t maximal = 0;

        for (uint64_t i = 0; i < bound; i++) {
            for (uint64_t j = 0; j < dim; j++) table[j] = cpy[j];

            uint64_t actual = 0;
            bool good = true;

            for (uint64_t j = 0; j < dim * dim; j++) {
                if (i & (1 << j)) {
                    actual++;
                    if (table[j / dim][j % dim] != '.') {
                        good = false;
                        break;
                    }
                    table[j / dim][j % dim] = 'R';
                }
            }

           if (good) {
                for (uint64_t j = 0; j < dim && good; j++) {
                    uint64_t c2 = 0;
                    uint64_t c1 = 0;
                    for (uint64_t k = 0; k < dim && good; k++) {
                        if (table[j][k] == 'R') {
                            c1++;
                        } else if (table[j][k] == 'X') {
                            c1 = 0;
                        }

                        if (table[k][j] == 'R') {
                            c2++;
                        } else if (table[k][j] == 'X') {
                            c2 = 0;
                        }

                        if (c1 > 1 || c2 > 1) good = false;
                    }
                }
                if (good) {
                    maximal = max(maximal, actual);
                }
            }
        }
        cout << maximal << endl;
    }
    return 0;
}