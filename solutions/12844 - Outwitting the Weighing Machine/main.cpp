#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int tc = 0; tc < test_cases; tc++) {
        int w[10];
        bool f[10];

        for (int i = 0; i < 10; i++) {
            cin >> w[i];
            f[i] = false;
        }

        int diff23 = w[1] - w[0];
        int diff34 = w[9] - w[8];
        int diff24 = diff23 + diff34;
        int diff15 = w[9] - w[0] - diff24;

        bool good = false;
        for (int w1 = 0; !good && w1 <= w[0]; w1++) {
            for (int w2 = 0; !good && w2 <= w[0] - w1; w2++) {
                int arr[10] =       {   w1 + w2,                    // 1st + 2nd
                                        w1 + w2 + diff23,           // 1st + 3rd
                                        w1 + w2 + diff24,           // 1st + 4th
                                        w1 + w1 + diff15,           // 1st + 5th
                                        w2 + w2 + diff23,           // 2nd + 3rd
                                        w2 + w2 + diff24,           // 2nd + 4th
                                        w2 + w1 + diff15,           // 2nd + 5th
                                        w2 + diff23 + w2 + diff24,  // 3rd + 4th
                                        w2 + diff23 + w1 + diff15,  // 3rd + 5th
                                        w2 + diff24 + w1 + diff15   // 4th + 5th
                                    };
                sort(arr, arr + 10);
                good = true;
                for (int i = 0; i < 10; i++) {
                    good = arr[i] == w[i];
                    if (!good) break;
                }

                if (good) {
                    cout << "Case " << tc + 1 << ": ";
                    cout << w1 << " " << w2 << " " << w2 + diff23 << " " << w2 + diff24 << " " << w1 + diff15 << endl;
                }
            }
        }
    }

    return 0;
}