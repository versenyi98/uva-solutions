#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<string> ignore;
	vector<pair<pair<string, vector<string>>, pair<int, int>>> result;


	string line;

	while (cin >> line, line != "::") {
		ignore.push_back(line);
	}

	getline(cin, line);

	while (getline(cin, line)) {
		size_t pos;
		vector<string> v;
		int ind = 0;

		vector<int> indexes;
		while (pos = line.find(' '), pos != string::npos) {
			v.push_back(line.substr(0, pos));
			line = line.substr(pos + 1);

			string lower = "";
			for (auto i : v.back()) {
				lower += tolower(i);
			}
			v[v.size() - 1] = lower;

			bool found = false;
			for (auto i : ignore) {
				if (i == lower) {
					found = true;
					break;
				}
			}
			if (!found) {
				indexes.push_back(ind);
			}
			ind++;
		}

		v.push_back(line);

		string lower = "";
		for (auto i : v.back()) {
			lower += tolower(i);
		}

		v[v.size() - 1] = lower;

		bool found = false;
		for (auto i : ignore) {
			if (i == lower) {
				found = true;
				break;
			}
		}
		if (!found) {
			indexes.push_back(ind);
		}

		for (auto i : indexes) {
			string upper = "";
			for (auto j : v[i]) {
				upper += toupper(j);
			}

			result.push_back({{upper, v}, {result.size(), i}});
		}
	}

	sort(result.begin(), result.end(), [] (pair<pair<string, vector<string>>, pair<int, int>> a, pair<pair<string, vector<string>>, pair<int, int>> b) {
		if (a.first.first != b.first.first) return a.first.first < b.first.first;
		if (a.second.first != b.second.first) return a.second.first < b.second.first;
		return a.second.second < b.second.second;
	});

	for (auto i : result) {
		for (int j = 0; j < i.first.second.size(); j++) {
			if (j) cout << ' ';
			if (j == i.second.second) {
				for_each(i.first.second[i.second.second].begin(), i.first.second[i.second.second].end(), [&](char & c) {
					c = toupper(c);
				});
			}
			cout << i.first.second[j];
		}
		cout << endl;
	}

	return 0;
}