#include <bits/stdc++.h>

using namespace std;

struct team {
	string name;

	int matches = 0;
	int wins = 0;
	int draws = 0;
	int losses = 0;

	int goals_for = 0;
	int goals_against = 0;

	int points = 0;

	bool operator<(const team t) const {
		if (points != t.points) return points > t.points;
		if (wins != t.wins) return wins > t.wins;
		if (goals_for - goals_against != t.goals_for - t.goals_against) return goals_for - goals_against > t.goals_for - t.goals_against;
		if (goals_for != t.goals_for) return goals_for > t.goals_for;
		if (matches != t.matches) return matches < t.matches;

		string n = name;
		string tn = t.name;

		for (int i = 0; i < n.length(); i++) n[i] = tolower(n[i]);
		for (int i = 0; i < tn.length(); i++) tn[i] = tolower(tn[i]);

		return n < tn;
	}
};

int main() {

	int test_cases;
	cin >> test_cases;
	string line;
	getline(cin, line);

	for (int tt = 0; tt < test_cases; tt++) {
		if (tt) cout << endl;
		string title;
		getline(cin, title);

		int team_count;
		cin >> team_count;
		getline(cin, line);

		map<string, team> teams_stats;
		string team_names[team_count];

		for (int i = 0; i < team_count; i++) {
			getline(cin, team_names[i]);
		}

		int matches_count;
		cin >> matches_count;
		getline(cin, line);

		for (int i = 0; i < matches_count; i++) {
			getline(cin, line);
			string team_a, team_b;
			int score_a, score_b;

			size_t pos = line.find('#');
			team_a = line.substr(0, pos);
			line = line.substr(pos + 1);

			pos = line.find('@');
			score_a = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			pos = line.find('#');
			score_b = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);

			team_b = line;

			if (score_a > score_b) {
				teams_stats[team_a].points += 3;
				teams_stats[team_a].wins++;
				teams_stats[team_b].losses++;
			} else if (score_a < score_b) {
				teams_stats[team_b].points += 3;
				teams_stats[team_b].wins++;
				teams_stats[team_a].losses++;
			} else {
				teams_stats[team_a].points++;
				teams_stats[team_b].points++;
				teams_stats[team_a].draws++;
				teams_stats[team_b].draws++;
			}

			teams_stats[team_a].matches++;
			teams_stats[team_b].matches++;

			teams_stats[team_a].goals_for += score_a;
			teams_stats[team_a].goals_against += score_b;
			teams_stats[team_b].goals_for += score_b;
			teams_stats[team_b].goals_against += score_a;
		}

		vector<team> teams_ranklist;

		for (int i = 0; i < team_count; i++) {
			teams_stats[team_names[i]].name = team_names[i];
			teams_ranklist.push_back(teams_stats[team_names[i]]);
		}

		sort(teams_ranklist.begin(), teams_ranklist.end());
		cout << title << endl;
		for (int i = 0; i < teams_ranklist.size(); i++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, teams_ranklist[i].name.c_str(), teams_ranklist[i].points, teams_ranklist[i].matches, teams_ranklist[i].wins, teams_ranklist[i].draws, teams_ranklist[i].losses, teams_ranklist[i].goals_for - teams_ranklist[i].goals_against, teams_ranklist[i].goals_for, teams_ranklist[i].goals_against);
		}
	}

	return 0;
}