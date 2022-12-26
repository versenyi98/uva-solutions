#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;
	int tc = 0;

	while (getline(cin, line)) {

		int table[3][3];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				table[i][j] = 0;
			}
		}

		for (auto i : line) {
			int command = (i - 'a');

			int x = command / 3;
			int y = command % 3;

			int xx[5] = {0, 0, 0, 1, -1};
			int yy[5] = {0, 1, -1, 0, 0};

			for (int j = 0; j < 5; j++) {
				if (x + xx[j] < 0 || x + xx[j] == 3 || y + yy[j] < 0 || y + yy[j] == 3) continue;
				table[x + xx[j]][y + yy[j]] = (table[x + xx[j]][y + yy[j]] + 1) % 10;
			}
		}
		cout << "Case #" << ++tc << ":" << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j) cout << ' ';
				cout << table[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}