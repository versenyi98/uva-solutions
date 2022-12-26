#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int ttt = 0; ttt < test_cases; ttt++) {
        int rows, cols, money;
        int A[100][100];

        cin >> rows >> cols >> money;
        int max_area = 0;
        int max_price = money;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> A[i][j];

                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = i; k < rows; k++) {
                    for (int l = j; l < cols; l++) {
                        int area = (k - i + 1) * (l - j + 1);
                        int cost = A[k][l];

                        if (i > 0) cost -= A[i - 1][l];
                        if (j > 0) cost -= A[k][j - 1];
                        if (i > 0 && j > 0) cost += A[i - 1][j - 1];

                        if ((area > max_area && cost <= money) ||
                            (area == max_area && cost < max_price)) {
                                max_price = cost;
                                max_area = area;
                        }
                    }
                }
            }
        }

        cout << "Case #" << ttt + 1 << ": " << max_area << " " <<
             (max_area ? max_price : 0) << endl;
    }
}