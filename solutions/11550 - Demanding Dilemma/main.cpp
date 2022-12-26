#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n, m;
		cin >> n >> m;

		int M[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> M[i][j];
			}
		}

		set<pair<int, int>> S;
		bool wrong = false;
		for (int i = 0; i < m; i++) {
			int counter = 0;
			int f, s;

			for (int j = 0; j < n; j++) {
				if (M[j][i] == 1) {
					counter++;
					if (counter == 1) {
						f = j;
					} else {
						s = j;
					}
				}
			}

			if (counter != 2 || S.find({f, s}) != S.end()) {
				wrong = true;
				break;
			} else {
				S.insert({f, s});
			}
		}

		if (wrong) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

	return 0;
}