#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int test_cases;
	string line;

	cin >> test_cases;

	while (test_cases--) {
		map<char, vector<char>> edges;
		map<char, bool> visited;

		while (cin >> line, line.find('*') == string::npos) {
			edges[line[1]].push_back(line[3]);
			edges[line[3]].push_back(line[1]);
		}

		cin >> line;

		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i])) {
				visited[line[i]] = false;
			}
		}

		int acorn = 0, tree = 0;

		for (auto i : visited) {
			if (!i.second) {
				int counter = 0;
				queue<char> q;
				q.push(i.first);

				while (q.size()) {
					auto front = q.front();
					q.pop();

					if (visited[front]) continue;
					visited[front] = true;

					counter++;
					for (auto j : edges[front]) {
						if (visited[j]) continue;
						q.push(j);
					}
				}

				if (counter == 1) {
					acorn++;
				} else {
					tree++;
				}
			}
		}
		cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
	}

	return 0;
}