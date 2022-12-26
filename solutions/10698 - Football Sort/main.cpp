#include <bits/stdc++.h>

using namespace std;

struct team {
	string name;
	int games = 0;

	int points = 0;
	int goals_for = 0;
	int goals_against = 0;

	bool operator< (const team t) const {
		if (points != t.points) return points > t.points;
		if (goals_for - goals_against != t.goals_for - t.goals_against) return goals_for - goals_against > t.goals_for - t.goals_against;
		if (goals_for != t.goals_for) return goals_for > t.goals_for;

		string n = name;
		string tn = t.name;

		for (int i = 0; i < n.length(); i++) n[i] = tolower(n[i]);
		for (int i = 0; i < tn.length(); i++) tn[i] = tolower(tn[i]);

		return n < tn;
	}
};

int main() {

	int T, G;
	int tt = 0;
	while (cin >> T >> G, T || G) {
		if (tt++) cout << endl;
		map<string, team> teams;
		string team_names[T];

		for (int i = 0; i < T; i++) cin >> team_names[i];
		for (int i = 0; i < G; i++) {
			string h, a;
			int hs, as;
			char dash;

			cin >> h >> hs >> dash >> as >> a;

			teams[h].games++;
			teams[a].games++;

			teams[h].goals_for += hs;
			teams[h].goals_against += as;

			teams[a].goals_for += as;
			teams[a].goals_against += hs;

			if (hs > as) {
				teams[h].points += 3;
			} else if (hs < as) {
				teams[a].points += 3;
			} else {
				teams[a].points++;
				teams[h].points++;
			}
		}

		vector<team> ranklist;
		for (auto t : team_names) {
			teams[t].name = t;
			ranklist.push_back(teams[t]);
		}

		sort(ranklist.begin(), ranklist.end());

		int last_point = INT_MIN;
		int last_goal_diff = INT_MIN;
		int last_goals_for = INT_MIN;

		for (int i = 0; i < ranklist.size(); i++) {
			if (ranklist[i].points == last_point && ranklist[i].goals_for == last_goals_for && ranklist[i].goals_for - ranklist[i].goals_against == last_goal_diff) {
				printf("%19s%4d%4d%4d%4d%4d", ranklist[i].name.c_str(), ranklist[i].points, ranklist[i].games, ranklist[i].goals_for, ranklist[i].goals_against, ranklist[i].goals_for - ranklist[i].goals_against);
			} else {
				printf("%2d.%16s%4d%4d%4d%4d%4d", i + 1, ranklist[i].name.c_str(), ranklist[i].points, ranklist[i].games, ranklist[i].goals_for, ranklist[i].goals_against, ranklist[i].goals_for - ranklist[i].goals_against);
			}

			if (ranklist[i].games) {
				printf("%7.2f\n", ranklist[i].points / (ranklist[i].games * 3.0) * 100);
			} else {
				printf("    N/A\n");
			}

			last_point = ranklist[i].points;
			last_goal_diff = ranklist[i].goals_for - ranklist[i].goals_against;
			last_goals_for = ranklist[i].goals_for;
		}
	}

	return 0;
}