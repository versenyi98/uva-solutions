#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;

	while (getline(cin, line)) {

		int count[52] = {0};
		int maximum = 0;

		for (auto c : line) {
			if (isalpha(c)) {
				if (isupper(c)) {
					count[c - 'A']++;
					maximum = max(maximum, count[c - 'A']);
				} else {
					count[c - 'a' + 26]++;
					maximum = max(maximum, count[c - 'a' + 26]);
				}
			}
		}

		for (int i = 0; i < 52; i++) {
			if (count[i] == maximum) {
				if (i < 26) {
					cout << (char)('A' + i);
				} else {
					cout << (char)('a' + i - 26);
				}
			}
		}

		cout << ' ' << maximum << endl;
	}

	return 0;
}