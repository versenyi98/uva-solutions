#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;

	while (cin >> m >> n) {
		int sol[n][m];
		int T[n][m];
		int sz[n];

		for (int i = 0; i < n; i++) {
			sz[i] = 0;
			for (int j = 0; j < m; j++) {
				T[i][j] = 0;
				sol[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			int nums;
			cin >> nums;

			int idxs[nums];

			for (int j = 0; j < nums; j++) {
				cin >> idxs[j];
			}

			for (int j = 0; j < nums; j++) {
				int val;
				cin >> val;
				sol[idxs[j] - 1][sz[idxs[j] - 1]++] = i + 1;
				T[idxs[j] - 1][i] = val;
			}
		}
		cout << n << " " << m << endl;
		for (int i = 0; i < n; i++) {
			cout << sz[i];
			for (int j = 0; j < sz[i]; j++) {
				cout << ' ' << sol[i][j];
			}
			cout << endl;
			for (int j = 0; j < sz[i]; j++) {
				if (j) cout << ' ';
				cout << T[i][sol[i][j] - 1];
			}
			cout << endl;
		}
	}

	return 0;
}