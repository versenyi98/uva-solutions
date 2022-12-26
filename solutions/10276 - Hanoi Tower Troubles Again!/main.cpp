#include <bits/stdc++.h>

using namespace std;

uint64_t precalculate(int pegs) {

	// Takes to much space and time, but recognized a pattern

	vector<int> state;
	for (int i = 0; i < pegs; i++) state.push_back(0);

	stack<pair<vector<int>, uint64_t>> q;

	q.push({state, 1});
	uint64_t sol = 0;
	while (q.size()) {
		auto top = q.top();
		q.pop();
		sol = max(sol, top.second);
		for (int i = 0; i < pegs; i++) {
			if (top.first[i] == 0) {
				vector<int> cop = top.first;
				cop[i] = top.second;
				q.push({cop, top.second + 1});
				break;
			} else {
				int sq = sqrt(top.first[i] + top.second);
				if (sq * sq == top.first[i] + top.second) {
					vector<int> cop = top.first;
					cop[i] = top.second;
					q.push({cop, top.second + 1});
				}
			}
		}
	}

	return sol;
}

int solution[51];

int main() {

	int diff = 2;
	solution[0] = 0;

	for (int i = 0; i < 51;) {
		solution[i + 1] = solution[i] + diff;
		solution[i + 2] = solution[i + 1] + diff;
		diff += 2;
		i++; i++;
	}

	int tests;
	cin >> tests;

	while (tests--) {
		int n;
		cin >> n;
		cout << solution[n] - 1 << endl;
	}

	return 0;
}