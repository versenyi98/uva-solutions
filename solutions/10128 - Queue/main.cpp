#include <bits/stdc++.h>

using namespace std;

int main() {

	uint64_t res[14][14][14];

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			for (int k = 0; k < 14; k++) {
				res[i][j][k] = 0;
			}
		}
	}

	res[1][1][1] = 1;

	for (int n = 2; n <= 13; n++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				// base case: n = 4 i = 2 j = 2
				// 1 n = 3 i = 1 j = 2  --->  3 1 2 ---> 4 2 3 ---> 1 4 2 3
				// 2 n = 3 i = 2 j = 1  --->  2 1 3 ---> 3 2 4 ---> 3 2 4 1
				// 3 n = 3 i = 2 j = 2  --->  1 3 2, 2 3 1 ---> 2 . 4 . 3, 3 . 4 . 2
				res[n][i][j] = res[n - 1][i - 1][j] + res[n - 1][i][j - 1] + (n - 2) * res[n - 1][i][j];
			}
		}
	}

	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		int i, j, k;
		cin >> i >> j >> k;
		cout << res[i][j][k] << endl;
	}

	return 0;
}