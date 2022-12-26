#include <iostream>

using namespace std;

int n;
char picture[25][25];

void floodFill(int i, int j) {

    if (i < 0 || j < 0 || i >= n || j >= n) return;
    if (picture[i][j] == '0') return;

    picture[i][j] = '0';

    floodFill(i - 1, j - 1);
    floodFill(i - 1, j    );
    floodFill(i - 1, j + 1);
    
    floodFill(i    , j - 1);
    floodFill(i    , j + 1);

    floodFill(i + 1, j - 1);
    floodFill(i + 1, j    );
    floodFill(i + 1, j + 1);
}

int main() {

    int test_cases = 1;
    while (cin >> n) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> picture[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == '1') {
                    result++;
                    floodFill(i, j);
                }
            }
        }
        cout << "Image number " << test_cases++ << " contains " << result << " war eagles." << endl;
    }
}