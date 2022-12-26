#include <bits/stdc++.h>

using namespace std;

int main() {

	int B, X, Y, N;

	while (cin >> B >> X >> Y >> N, B || X || Y || N) {

		map<int, int> attacks;

		for (int i = 0; i < B; i++) {
			attacks[i] = (i + 1) % B;
		}

		int battlefield[X][Y];

		for (int i = 0; i < X; i++) {
			for (int j = 0; j < Y; j++) {
				cin >> battlefield[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			vector<pair<pair<int, int>, pair<int, int>>> attacked;

			for (int j = 0; j < X; j++) {
				for (int k = 0; k < Y; k++) {
					int x[] = {-1, +1, 0, 0};
					int y[] = {0, 0, -1, +1};

					for (int l = 0; l < 4; l++) {
						int xx = j + x[l];
						int yy = k + y[l];

						if (xx < 0 || xx == X || yy < 0 || yy == Y || battlefield[xx][yy] != attacks[battlefield[j][k]]) continue;
						attacked.push_back({{battlefield[j][k], attacks[battlefield[j][k]]}, {xx, yy}});
					}
				}
			}

			while (attacked.size()) {
				battlefield[attacked.back().second.first][attacked.back().second.second] = attacked.back().first.first;
				attacked.pop_back();
			}
		}

		for (int ii = 0; ii < X; ii++) {
			for (int jj = 0; jj < Y; jj++) {
				if (jj) cout << ' ';
				cout << battlefield[ii][jj];
			}
			cout << endl;
		}
	}

	return 0;
}