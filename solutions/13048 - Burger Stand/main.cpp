#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;
	string line;
	for (int tt = 1; tt <= test_cases; tt++) {
		cin >> line;
		bool good[line.length()];

		for (int i = 0; i < line.length(); i++) {
			good[i] = true;
		}

		for (int i = 0; i < line.length(); i++) {
			if (line[i] == 'B') {
				good[i] = false;
				if (i - 1 >= 0) {
					good[i - 1] = false;
				}
				if (i - 2 >= 0) {
					good[i - 2] = false;
				}
			}

			if (line[i] == 'D') {
				good[i] = false;
			}

			if (line[i] == 'S') {
				good[i] = false;
				if (i - 1 >= 0) {
					good[i - 1] = false;
				}
				if (i + 1 < line.length()) {
					good[i + 1] = false;
				}
			}
		}
		int cc = 0;
		for (int i = 0; i < line.length(); i++) {
			if (good[i]) cc++;
		}
		cout << "Case " << tt << ": " << cc << endl;
	}

	return 0;
}