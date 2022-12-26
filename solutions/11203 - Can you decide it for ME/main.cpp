#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	while (n--) {
		string line;
		cin >> line;

		int x = 0, y = 0, z = 0;

		bool found_M = false;
		bool found_E = false;

		for (int i = 0; i < line.length(); i++) {
			if (line[i] != '?' && line[i] != 'M' && line[i] != 'E') {
				x = 0;
				break;
			}

			if (line[i] == 'M') {
				if (found_M || found_E) {
					x = 0;
					break;
				} else {
					found_M = true;
					continue;
				}
			}

			if (line[i] == 'E') {
				if (!found_M || found_E) {
					x = 0;
					break;
				} else {
					found_E = true;
					continue;
				}
			}

			if (found_E) {
				z++;
			} else if (found_M) {
				y++;
			} else {
				x++;
			}
		}

		if (found_E && found_M && x * y * z && x + y == z) {
			cout << "theorem" << endl;
		} else {
			cout << "no-theorem" << endl;
		}
	}

	return 0;
}