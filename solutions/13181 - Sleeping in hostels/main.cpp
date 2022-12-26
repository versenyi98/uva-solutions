#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;

	while (cin >> line) {
		bool first = true;
		int maximum = 0;
		int counter = 0;

		for (auto ch : line) {
			if (ch == 'X' && first) {
				maximum = max(maximum, counter - 1);
				counter = 0;
				first = false;
			} else if (ch == 'X') {
				maximum = max((counter - 1) / 2, maximum);
				counter = 0;
			} else if (ch == '.') {
				counter++;
			}
		}

		maximum = max(counter - 1, maximum);
		cout << maximum << endl;
	}

	return 0;
}