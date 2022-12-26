#include <bits/stdc++.h>

using namespace std;

int main() {

    int r, c, cc;

    while (cin >> r >> c >> cc, r || c || cc) {
        char table[r][c];
        int visited[r][c];

        for  (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                visited[i][j] = -1;
                cin >> table[i][j];
            }
        }

        int x = 0, y = cc - 1;
        
        int counter = 0;
        while (x >= 0 && x < r && y >= 0 && y < c && visited[x][y] == -1) {
            visited[x][y] = counter++;

            if (table[x][y] == 'W') {
                y--;
            } else if (table[x][y] == 'E') {
                y++;
            } else if (table[x][y] == 'S') {
                x++;
            } else if (table[x][y] == 'N') {
                x--;
            } 
        }

        if (x < 0 || x == r || y < 0 || y == c) {
            cout << counter << " step(s) to exit\n";
        } else {
            cout << visited[x][y] << " step(s) before a loop of " << counter - visited[x][y] << " step(s)\n";
        }
    }
}