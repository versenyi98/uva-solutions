#include <bits/stdc++.h>

using namespace std;

struct team {
	int ID;
	map<char, int> problem_tried;
	map<char, bool> problem_success;
	int problems_solved = 0;
	int time_passed = 0;

	bool operator<(const team t) const {
		if (problems_solved != t.problems_solved) {
			return problems_solved > t.problems_solved;
		}

		if (time_passed != t.time_passed) {
			return time_passed < t.time_passed;
		}

		return ID < t.ID;
	}
};

struct submission {
	int ID;
	char problem;
	int hour;
	int minute;
	char success;

	bool operator<(const submission sub) const {
		return hour < sub.hour || (hour == sub.hour && minute < sub.minute) || (hour == sub.hour && minute == sub.minute && success < sub.success);
	}
};

int main() {

	int test_cases = 0;
	cin >> test_cases;
	string line;

	getline(cin, line);
	getline(cin, line);

	for (int tt = 0; tt < test_cases; tt++) {

		if (tt) cout << endl;
		int teamm, hour, min_;
		char problem, sep, verdict;

		int max_team = 0;

		map<int, team> ranklist;
		vector<team> teams;
		vector<submission> submissions;
		while (getline(cin, line) && line.length()) {

			size_t pos = line.find(' ');
			teamm = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			pos = line.find(' ');
			problem = line.substr(0, pos)[0];
			line = line.substr(pos + 1);

			pos = line.find(':');
			hour = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			pos = line.find(' ');
			min_ = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			verdict = line[0];

			submission sub;

			max_team = max(max_team, teamm);

			sub.hour = hour;
			sub.minute = min_;
			sub.ID = teamm;
			sub.problem = problem;
			sub.success = verdict;

			submissions.push_back(sub);
		}

		sort(submissions.begin(), submissions.end());

		for (auto sub : submissions) {
			if (ranklist[sub.ID].problem_success[sub.problem]) continue;
			ranklist[sub.ID].ID = sub.ID;

			if (sub.success == 'Y') {
				ranklist[sub.ID].problem_success[sub.problem] = true;
				ranklist[sub.ID].problems_solved++;
				ranklist[sub.ID].time_passed += 60 * sub.hour + sub.minute + 20 * ranklist[sub.ID].problem_tried[sub.problem];
			} else {
				ranklist[sub.ID].problem_tried[sub.problem]++;
			}
		}

		for (int i = 1; i <= max_team; i++) {
			ranklist[i].ID = i;
			teams.push_back(ranklist[i]);
		}

		sort(teams.begin(), teams.end());

		int last_point = -1;
		int last_time = -1;
		int tie = 0;
		int pos = 0;

		cout << "RANK TEAM PRO/SOLVED TIME\n";
		for (auto t : teams) {
			if (t.problems_solved == last_point && t.time_passed == last_time) {
				tie++;
			} else {
				pos += tie + 1;
				tie = 0;
			}

			last_point = t.problems_solved;
			last_time = t.time_passed;
			if (t.problems_solved) {
				printf("%4d %4d %4d %10d\n", pos, t.ID, t.problems_solved, t.time_passed);
			} else {
				printf("%4d %4d\n", pos, t.ID);
			}
		}
	}

	return 0;
}