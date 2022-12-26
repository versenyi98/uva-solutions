#include <bits/stdc++.h>

using namespace std;

struct contestant {
	int ID = 0;
	int points = 0;
	map<int, int> problem_fails;
	map<int, bool> problem_solved;
	int time_penalty = 0;

	bool operator<(const contestant cont) const {
		if (cont.points != points) return points > cont.points;
		if (cont.time_penalty != time_penalty) return time_penalty < cont.time_penalty;
		return ID < cont.ID;
	}
};

int main() {

	int test_cases;
	cin >> test_cases;

	string line;
	getline(cin, line);
	getline(cin, line);

	for (int tt = 0; tt < test_cases; tt++) {
		map<int, contestant> contestants;
		while(getline(cin, line) && line.length()) {
			int ID, problem, time_;
			char result;

			size_t pos = line.find(' ');
			ID = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			pos = line.find(' ');
			problem = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			pos = line.find(' ');
			time_ = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			result = line[0];

			contestants[ID].ID = ID;

			if (result == 'C' && !contestants[ID].problem_solved[problem]) {
				contestants[ID].problem_solved[problem] = true;
				contestants[ID].points++;
				contestants[ID].time_penalty += contestants[ID].problem_fails[problem] * 20 + time_;
			}

			if (result == 'I' && !contestants[ID].problem_solved[problem]) {
				contestants[ID].problem_fails[problem]++;
			}
		}
		vector<contestant> v;
		for (auto cont : contestants) {
			v.push_back(cont.second);
		}

		sort(v.begin(), v.end());
		if (tt) cout << endl;
		for (auto i : v) {
			cout << i.ID << ' ' << i.points << ' ' << i.time_penalty << endl;
		}
	}

	return 0;
}