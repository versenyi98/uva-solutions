#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int img[200][200];
int height, width;

void floodFill(int brush, int i, int j, int source) {

  if (i < 0 || j < 0 || i >= height || j >= width * 4|| img[i][j] != source)  return;
    img[i][j] = brush;

    floodFill(brush, i + 1, j, source);
    floodFill(brush, i - 1, j, source);
    floodFill(brush, i, j + 1, source);
    floodFill(brush, i, j - 1, source);
}

int main() {

  char holesToSign[6] = {'W', 'A', 'K', 'J', 'S', 'D' };

  int number = 0;

  while (true) {
    cin >> height >> width;

    number++;

    if (height == 0 && width == 0) {
      return 0;
    }

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {

        int l = 8;
        int hexa;

        scanf("%1x", &hexa);

        for (int k = 0; k < 4; k++) {
          img[i][j * 4 + k] = (hexa & l ? 1 : 0);
          l = l >> 1;
        }
      }
    }


    int brush = 2;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width * 4; j++) {
        if (img[i][j] == 1) {
          floodFill(brush, i, j, 1);
          brush++;
        }
      }
    }

    int holes[brush];
    for (int i = 0; i < brush; i++) {
      holes[i] = 0;
    }
/*
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width * 4; j++) {
        cout << img[i][j];
      }
      cout << endl;
    }
*/
    for (int i = 0; i < width * 4; i++) {

      if (img[0][i] == 0) {
        floodFill(1, 0, i, 0);
      }

      if (img[height - 1][i] == 0) {
        floodFill(1, height - 1, i, 0);
      }

    }

    for (int i = 0; i < height; i++) {

      if (img[i][0] == 0) {
        floodFill(1, i, 0, 0);
      }

      if (img[i][width * 4 - 1] == 0) {
        floodFill(1, i, width * 4 - 1, 0);
      }

    }

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width * 4; j++) {
        if (img[i][j] == 0) {
          int color = img[i][j - 1];

          holes[color]++;
          floodFill(color, i, j, 0);
        }
      }
    }

    string return_val = "";

    for (int i = 2; i < brush; i++) {
      return_val += holesToSign[holes[i]];
    }

    std::sort(return_val.begin(), return_val.end());
    cout << "Case " << number << ": " + return_val << endl;

  }
}
