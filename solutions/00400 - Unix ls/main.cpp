#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	while (cin >> n) {
		vector<string> names;
		int longest = 0;
		string line;
		for (int i = 0; i < n; i++) {
			cin >> line;
			names.push_back(line);
			longest = max(longest, (int)names[i].length());
		}

		sort(names.begin(), names.end());

		int cols = 0;
		int space = 60;

		space -= longest;
		cols++;
		int rows = 0;
		while (space - longest - 2 >= 0) {
			space = space - longest - 2;
			cols++;
		}

		int cc = 0;

		while (cc < n) {
			cc += cols;
			rows++;
		}

		cout << "------------------------------------------------------------" << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols && i + j * rows < n; j++) {
				cout << names[i + j * rows];
				for (int k = names[i + j * rows].length(); k < longest; k++) {
					cout << ' ';
				}
				if (j != cols - 1 && i + (j + 1) * rows < n) {
					cout << "  ";
				}
			}
			cout << endl;
		}
	}

	return 0;
}