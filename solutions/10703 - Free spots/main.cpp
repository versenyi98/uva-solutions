#include <bits/stdc++.h>

using namespace std;

int main() {

    int h, w, n;
    int tt = 0;
    while (cin >> w >> h >> n, h || w || n) {

        bool board[w][h];

        int empty = h * w;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                board[i][j] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            for (int j = min(x1 - 1, x2 - 1); j <= max(x2 - 1, x1 - 1); j++) {
                for (int k = min(y1 - 1, y2 - 1); k <= max(y2 - 1, y1 - 1); k++) {
                    if (board[j][k]) empty--;
                    board[j][k] = false;
                }
            }
        }
        if (empty == 0) {
            cout << "There is no empty spots." << endl;
        } else if (empty == 1) {
            cout << "There is one empty spot." << endl;
        } else {
            cout << "There are " << empty << " empty spots." << endl;
        }
    }
}