#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> idx_map;

void generate() {

	string current = "a";
	int idx = 1;

	while (current.size() <= 5) {
		idx_map[current] = idx;

		int step_back = current.size() - 1;

		while (step_back >= 0 && current[step_back] > ('z' - current.size() + step_back)) {
			step_back--;
		}

		if (step_back == -1) {
			current.push_back('a');
			for (int i = 0; i < current.size(); i++) current[i] = 'a' + i;
			idx++;
		} else {
			current[step_back]++;
			for (int i = step_back + 1; i < current.size(); i++) {
				current[i] = current[i - 1] + 1;
			}
			idx++;
		}
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);

	generate();

	string line;
	while (cin >> line) cout << idx_map[line] << endl;

	return 0;
}