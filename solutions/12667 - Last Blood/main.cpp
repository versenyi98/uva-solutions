#include <bits/stdc++.h>

using namespace std;

int main() {

	int problems, teams, submissions;

	cin >> problems >> teams >> submissions;

	map<pair<int, char>, bool> has_solved;
	map<char, pair<int, int>> last_blood;

	for (int i = 0; i < submissions; i++) {
		int time, team;
		char problem;
		string result;

		cin >> time >> team >> problem >> result;

		if (result == "Yes" && !has_solved[{team, problem}]) {
			last_blood[problem] = {team, time};
			has_solved[{team, problem}] = true;
		}
	}

	for (char c = 'A'; c < 'A' + problems; c++) {
		if (last_blood[c] == make_pair(0, 0)) {
			cout << c << " - -\n";
		} else {
			cout << c << ' ' << last_blood[c].second << ' ' << last_blood[c].first << endl;
		}
	}

	return 0;
}