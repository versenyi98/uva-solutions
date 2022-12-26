#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n, m;
	unordered_map<string, double> percentage;

	cin >> n >> m;

	while (n--) {
		string party;
		double pc;

		cin >> party >> pc;
		percentage[party] = pc;
	}

	string line;

	getline(cin, line);

	for (int i = 0; i < m; i++) {
		getline(cin, line);
		stringstream sstream;

		sstream << line;

		double sum = 0.0;

		while (true) {
			string current;
			sstream >> current;

			sum += percentage[current];

			sstream >> current;

			if (current != "+") {
				string op = current;

				sstream >> current;
				double d = stod(current);

				if (op == "=") {
					cout << "Guess #" << i + 1 << " was " << (abs(d - sum) < 0.001 ? "correct" : "incorrect") << "." << endl;
				} else if (op == "<") {
					cout << "Guess #" << i + 1 << " was " << (abs(d - sum) > 0.001 && d > sum ? "correct" : "incorrect") << "." << endl;
				} else if (op == ">") {
					cout << "Guess #" << i + 1 << " was " << (abs(d - sum) > 0.001 && d < sum ? "correct" : "incorrect") << "." << endl;
				} else if (op == "<=") {
					cout << "Guess #" << i + 1 << " was " << (abs(d - sum) < 0.001 || d > sum ? "correct" : "incorrect") << "." << endl;
				} else if (op == ">=") {
					cout << "Guess #" << i + 1 << " was " << (abs(d - sum) < 0.001 || d < sum ? "correct" : "incorrect") << "." << endl;
				}
				break;
			}
		}
	}

	return 0;
}