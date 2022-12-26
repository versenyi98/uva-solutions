#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;

	string line;
	getline(cin, line);

	for (int tt = 0; tt < test_cases; tt++) {
		map<string, string> first, second;

		string key, value;
		size_t pos;

		getline(cin, line);
		line = line.substr(1);
		line.pop_back();

		bool last = true;
		while (pos = line.find(','), line.length() && (pos != string::npos || last)) {
			if (pos == string::npos) last = false;

			size_t sep = line.find(':');
			key = line.substr(0, sep);
			value = line.substr(sep + 1, pos - sep - 1);
			line = line.substr(pos + 1);

			first[key] = value;
		}

		getline(cin, line);
		line = line.substr(1);
		line.pop_back();
		last = true;
		while (pos = line.find(','), line.length() && (pos != string::npos || last)) {
			if (pos == string::npos) last = false;

			size_t sep = line.find(':');
			key = line.substr(0, sep);
			value = line.substr(sep + 1, pos - sep - 1);
			line = line.substr(pos + 1);

			second [key] = value;
		}

		set<string> res[3];
		char sign[3] = {'+', '-', '*'};
		for (auto i : first) {
			if (second.find(i.first) == second.end()) {
				res[1].insert(i.first);
			} else if (second[i.first] != i.second) {
				res[2].insert(i.first);
			}
		}

		for (auto i : second) {
			if (first.find(i.first) == first.end()) {
				res[0].insert(i.first);
			}
		}

		if (res[0].size() + res[1].size() + res[2].size()) {
			for (int i = 0; i < 3; i++) {
				if (res[i].size() == 0) continue;
				cout << sign[i];
				bool f = true;
				for (auto j : res[i]) {
					if (!f) {
						cout << ',';
					} else {
						f = false;
					}
					cout << j;
				}
				cout << endl;
			}
		} else {
			cout << "No changes" << endl;
		}
		cout << endl;
	}

	return 0;
}