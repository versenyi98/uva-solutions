#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	string line;
	getline(cin, line);

	for (int tt = 0; tt < test_cases; tt++) {
		if (tt) cout << endl;
		getline(cin, line);

		unordered_map<int, bool> ignored;
		unordered_map<int, char> mode;
		unordered_map<int, set<int>> owner;
		unordered_map<int, bool> occured;
		while (getline(cin, line) && line != "#") {
			char m;
			int id, owned;

			stringstream ss;
			ss << line;
			ss >> m >> id >> owned;

			if (ignored[id]) {
				cout << "IGNORED" << endl;
			} else if (occured[owned] && (mode[owned] == 'X' || m == 'X') && owner[owned].size() - owner[owned].count(id)) {
				cout << "DENIED" << endl;
				ignored[id] = true;
			} else {
				cout << "GRANTED" << endl;
				if (m == 'X' || mode[owned] == 'X') {
					mode[owned] = 'X';
				} else {
					mode[owned] = 'S';
				}
				owner[owned].insert(id);
				occured[owned] = true;
			}
		}
	}

	return 0;
}